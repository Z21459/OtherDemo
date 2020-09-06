local skynet = require "skynet"
local debugchannel = require "skynet.debugchannel"

local CMD = {}

local channel
local addre = {}
function CMD.start(address, fd)--��debug_console������ַ������
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
	table.insert(addre,address)--����ַ����������
	skynet.exit()
end

--�Զ��庯�� ���и��²���
--����debug������������ �ж��Ƿ���뵽 inject��ȥ
function CMD.debugin(cmdline)
	if not _P then
        print("hotfix fail, no _P define")
        return
	end

	print("hotfix begin")

-- ���ڻ�ȡ��������
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

	-- ��ȡԭ���ĺ�����ַ������������
	local command = _P.lua.command
	local upvs = get_up(command.do_test)--�������ȡ������ַ
	local test = upvs.test--��ȡ�������õ�ַ

	command.do_test = function(msg)
    test(cmdline,'New ' .. msg)--�����´�ӡ����  ���������е�ֵ��ӡ
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
	--������������󣬿������ý���inject��
	--CMD.debugin(cmdline)--�����������

	address = addre[1] --��õ�ַ
	local filename = "./bin/testinject/inject_test.lua"
	CMD.inject(address,filename,...)--�����ֵ ������������debuginject���   address����ͨ��cmd��һ��ֱ�Ӵ�
	
	--����injct�������  ��filename ��source�滻 address �Ѿ�����
	channel:write(cmdline)-- ��debug���д�ӡ��
end

function CMD.ping()
	skynet.ret()
end

skynet.start(function()--��debug_console ���뵽 start�������
	skynet.dispatch("lua", function(_,_,cmd,...)
		local f = CMD[cmd]
		print("startf",f)
		f(...)
	end)
end)
