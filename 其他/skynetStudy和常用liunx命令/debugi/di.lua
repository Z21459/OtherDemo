
...就是不定参数arg，没规定几个参数
function czf(i,...)
	print(i)
	print(...)
	print(type(...))
	print(arg[1])--arg等价于...
	print(arg[3])	
end
czf(1,2,3,4,5)
1 table一个地址 table 2 4


--相当于一个服务一直给另一个服务发消息
--子服务，相当于debug_console方  master相当于主服务接收方 cputime相当于数据
local r = cluster.send("master",".mainServer","cluster10",cputime)
loca p = skynet.send("","","",mag)


--主服务接收消息
local function dosomething(session, address, ...)

        skynet.error("session", session)
        skynet.error("address", skynet.address(address))
        local args = {...}
        for i,v in pairs(args) do
                skynet.error("arg"..i..":", v)
        end
        print("main11")
end


skynet.start(function()
        skynet.dispatch("lua", function(session, address, ...)
                dosomething(session,address, ...)
        end)
        skynet.register(".mainServer")

end)






--共享内存  消息队列    进程之间传递消息


--自定义函数 进行更新操作
--根据debug里面输入命令 判断是否进入到 inject中去
local function debugin(cmdline)--只传入这一个要输入的代码数据
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
		test('New ' .. msg)--重新新打印函数
		test(cmdline)--新传入数值
	end
	print("hotfix end")
end


--上面相当于生成了.lua文件  然后根据.lua文件  输入到inject中
