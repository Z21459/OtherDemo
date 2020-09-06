local skynet = require "skynet"
local debugchannel = require "skynet.debugchannel"

local CMD = {}

local channel
local addre = {}
function CMD.start(address, fd)--从debug_console传来地址和数据
	assert(channel == nil, "start more than once")
	skynet.error(string.format("Attach to :%08x", address))
	local handle
	channel, handle = debugchannel.create()
	local ok, err = pcall(skynet.call, address, "debug", "REMOTEDEBUG", fd, handle)
	if not ok then
		skynet.ret(skynet.pack(false, "Debugger attach failed"))
	else
		-- todo hook
		skynet.ret(skynet.pack(true))
	end
	table.insert(addre,address)--将地址保存在这里
	skynet.exit()
end

--自定义函数 进行更新操作
--根据debug里面输入命令 判断是否进入到 inject中去
function CMD.debugin(cmdline)
	if not _P then
        print("hotfix fail, no _P define")
        return
	end

	print("hotfix begin")

-- 用于获取函数变量
	local function get_up(f)
		local u = {}
		if not f then
                return u
        end
        local i = 1
        while true do
			local name, value = debug.getupvalue(f, i)
			if name == nil then
				return u
			end
			u[name] = value
			i = i + 1
        end
        return u
	end

	-- 获取原来的函数地址，及函数变量
	local command = _P.lua.command
	local upvs = get_up(command.do_test)--在这里获取函数地址
	local test = upvs.test--获取函数调用地址

	command.do_test = function(msg)
    test(cmdline,'New ' .. msg)--重新新打印函数  并吧命令行的值打印
	end
	print("hotfix end")
end

local function adjust_address(address)
	local prefix = address:sub(1,1)
	if prefix == '.' then
		return assert(skynet.localname(address), "Not a valid name")
	elseif prefix ~= ':' then
		address = assert(tonumber("0x" .. address), "Need an address") | (skynet.harbor(skynet.self()) << 24)
	end
	return address
end

function CMD.inject(address, filename, ...)
	address = adjust_address(address)
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


function CMD.cmd(cmdline)
	--进入这个函数后，可以设置进入inject中
	--CMD.debugin(cmdline)--调用这个函数

	address = addre[1] --获得地址
	local filename = "./bin/testinject/inject_test.lua"
	CMD.inject(address,filename,...)--这个传值 是利用上述的debuginject获得   address可以通过cmd上一层直接传
	
	--调用injct这个函数  将filename 和source替换 address 已经存在
	channel:write(cmdline)-- 在debug进行打印了
end

function CMD.ping()
	skynet.ret()
end

skynet.start(function()--从debug_console 进入到 start这个函数
	skynet.dispatch("lua", function(_,_,cmd,...)
		local f = CMD[cmd]
		print("startf",f)
		f(...)
	end)
end)
