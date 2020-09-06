local skynet = require "skynet"
local codecache = require "skynet.codecache"
local core = require "skynet.core"
local socket = require "skynet.socket"
local snax = require "skynet.snax"
local memory = require "skynet.memory"
local httpd = require "http.httpd"
local sockethelper = require "http.sockethelper"

local arg = table.pack(...)
assert(arg.n <= 2)
local ip = (arg.n == 2 and arg[1] or "127.0.0.2")
local port = tonumber(arg[arg.n])

local COMMAND = {}
local COMMANDX = {}


local function format_table(t)
	local index = {}
	for k in pairs(t) do
		table.insert(index, k)
	end
	table.sort(index, function(a, b) return tostring(a) < tostring(b) end)
	local result = {}
	for _,v in ipairs(index) do
		table.insert(result, string.format("%s:%s",v,tostring(t[v])))
	end
	return table.concat(result,"\t")
end

local function dump_line(print, key, value)
	if type(value) == "table" then
		print(key, format_table(value))
	else
		print(key,tostring(value))
	end
end

local function dump_list(print, list)
	local index = {}
	for k in pairs(list) do
		table.insert(index, k)
	end
	table.sort(index, function(a, b) return tostring(a) < tostring(b) end)
	for _,v in ipairs(index) do
		dump_line(print, v, list[v])
	end
end
local temcmd = {}

local function split_cmdline(cmdline)--尝试在这里判断 命令是否正确
	local value = {}
--	local index = 1
	print("split_cmdline",cmdline)
	local split = {}
	for i in string.gmatch(cmdline, "%S+") do
--		print("split",split,i)
		table.insert(split,i)
		table.insert(value,i)
	end
	print("resultsplit",split)--返回的只是一个table:ox地址
	table.insert(temcmd,split) --将值存入到列表 给调用debug 使用cmd用
	return split,value
end

local function docmd(cmdline, print, fd)
	local ret = {}
---	while true do
	local split ,ret= split_cmdline(cmdline)
--	end
	for i,v in pairs(ret) do
		print("ret",i,v,type(v))
	end
--	print("docmd",split)
	local command = nil
--	local command = split[1]
--	print("command",command)
	--20200221根据输入判断执行那个函数
	
	if (ret[3]== "d" and ret[1] == "debuginject") then
--		print("debug")
		command = "debug"
	elseif (ret[3]== "i" and ret[1] == "debuginject") then
		print("inejct")
		command = "inject"
	elseif (ret[3]== "di" and ret[1] == "debuginject") then--先执行inejct 然后执行debug
		command = "debuginject"
	else
		command = split[1]
		print(command)
	end
--	print("cmdline",cmdline)
--	table.insert(temcmd,cmdline)

--输入格式  debuginject address etype filename
--
--	print("docmd_command",command) --command 三种情况 debug inject debuginject  然后进入不同指令
	--如果解析的输入时d i di 三种状态 则进入相应的状态 分别执行不同函数
	local cmd = COMMAND[command]
--	print("docmd_cmd",cmd)
	local ok, list
	if cmd then--如果在COMMAND列表里
		ok, list = pcall(cmd, table.unpack(split,2))
	else--如果不在COMMAND列表  判断是否在COMMANDX
		cmd = COMMANDX[command]
		if cmd then
			split.fd = fd
			split[1] = cmdline
			ok, list = pcall(cmd, split)
		else
			print("Invalid command, type help for command list")
		end
	end

	if ok then
		if list then
			if type(list) == "string" then
				print(list)
			else
				dump_list(print, list)
			end
		end
		print("<CMD OK>")
	else
		print(list)
		print("<CMD Error>")
	end
end


local function console_main_loop(stdin, print)
	print("Welcome to skynet console")
	skynet.error(stdin, "connected")
	local ok, err = pcall(function()
		while true do
			local cmdline = socket.readline(stdin, "\n")
--			print("console_main_loop",cmdline)
			if not cmdline then
				break
			end
			if cmdline:sub(1,4) == "GET " then
				-- http
				local code, url = httpd.read_request(sockethelper.readfunc(stdin, cmdline.. "\n"), 8192)
				local cmdline = url:sub(2):gsub("/"," ")
				docmd(cmdline, print, stdin)
				break
			end
			if cmdline ~= "" then
				docmd(cmdline, print, stdin)
			end
		end
	end)
	if not ok then
		skynet.error(stdin, err)
	end
	skynet.error(stdin, "disconnected")
	socket.close(stdin)
end

skynet.start(function()
	local listen_socket = socket.listen (ip, port)
	skynet.error("Start debug console at " .. ip .. ":" .. port)
	socket.start(listen_socket , function(id, addr)
		local function print(...)
			local t = { ... }
			for k,v in ipairs(t) do
				t[k] = tostring(v)
			end
			socket.write(id, table.concat(t,"\t"))
			socket.write(id, "\n")
		end
		socket.start(id)
		skynet.fork(console_main_loop, id , print)
	end)
end)

function COMMAND.help()
	return {
		help = "This help message",
		list = "List all the service",
		debuginject = "debuginject address etype(d,i,di) filename",
		inject = "inject address luascript.lua",
		debug = "debug address : debug a lua service",
	}
end

local function adjust_address(address)
--	print("adjust_address",address)
	local prefix = address:sub(1,1)
	if prefix == '.' then
		return assert(skynet.localname(address), "Not a valid name")
	elseif prefix ~= ':' then
		address = assert(tonumber("0x" .. address), "Need an address") | (skynet.harbor(skynet.self()) << 24)
	end
	return address
end

function COMMAND.list()
	return skynet.call(".launcher","lua","LIST")
end

function COMMAND.inject(address,etype,filename, ...)
	print("Welcom inject")
	print("injectaddress",address,etype,filename,"type(filename)",type(filename))
	address = adjust_address(address)
--	print("injectaddress",address,filename,"type(filename)",type(filename))
	local f = io.open(filename, "rb")
	if not f then
		return "Can't open " .. filename
	end
	local source = f:read "*a"
	f:close()
	local ok, output = skynet.call(address, "debug", "RUN", source, filename, ...)
	if ok == false then
		error(output)
	end
	return output
end
--debuginject命令  先执行inject  然后执行debug
function COMMAND.debuginject(address, etype, filename, ...)
	print("Welcom debuginject")--首先进入inject 然后结束后进入到debud
	print("debuginjectaddress",address,etype,filename,"type(filename)",type(filename))
	COMMAND.inject(address,etype,filename, ...)

--[[	for i,v in pairs() do
		print("temcmd",i,v)
	end
	print("temcmd[1]",temcmd[1])
]]--
	for i,v in pairs(temcmd) do
		print("debuginjectcmdline",i,v)
	end
--	local cmd ,ret= split_cmdline(temcmd[2])--第二个值是地址 
	
	print("cmddddddddddd",temcmd[1])
	COMMANDX.debug(temcmd[1])
	
	print("debuginject,OK")

end

function COMMANDX.debug(cmd)
	print("Welocon debug")
	print("debugcmd",cmd)
--      print("debuginjectcmdline",temcmd[1])
--	local cmd1 ,ret= split_cmdline(temcmd[1])
--	print("debugtemcmd1",cmd1)
	address = adjust_address(cmd[2])
--	print("addressdebug",address)
	local agent = skynet.newservice "debug_agent"
	local stop
	local term_co = coroutine.running()
	local function forward_cmd()
		repeat
			-- notice :  It's a bad practice to call socket.readline from two threads (this one and console_main_loop), be careful.
			skynet.call(agent, "lua", "ping")	-- detect agent alive, if agent exit, raise error
--			print("cmdfd1",cmd.fd)
			local cmdline = socket.readline(cmd.fd, "\n")
			cmdline = cmdline and cmdline:gsub("(.*)\r$", "%1")
			if not cmdline then
				skynet.send(agent, "lua", "cmd", "cont")
				break
			end
			skynet.send(agent, "lua", "cmd", cmdline)
		until stop or cmdline == "cont"
	end
	skynet.fork(function()
		pcall(forward_cmd)
		if not stop then	-- block at skynet.call "start"
			term_co = nil
		else
			skynet.wakeup(term_co)
		end
	end)
--	print("cdmfd2",cmd.fd)
	local ok, err = skynet.call(agent, "lua", "start", address, cmd.fd)
	stop = true
	if term_co then
		-- wait for fork coroutine exit.
		skynet.wait(term_co)
	end

	if not ok then
		error(err)
	end

end
