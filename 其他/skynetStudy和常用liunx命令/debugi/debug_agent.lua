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


function CMD.cmd(cmdline)
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
