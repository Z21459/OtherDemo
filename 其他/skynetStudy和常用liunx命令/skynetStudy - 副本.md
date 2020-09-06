# 1.现在完成

最终实现目的是将debug和inject结合起来。，实现cluster中各lua虚拟机运行时的情况，并实现热更检测--实现inject像debug一样直接输入指令进行操作。。。。。阅读inject和debug_console 实现扩展debug_console

*在debug直接输入lua代码*

--将inject和debug结合起来   inject直接替换变量 而不是函数。。。。。。。

<!--*<u>------------------输入指令   debuginject address  -d(-di)(i) filename        使用-d(-di)(i)来区分是否inject debug或者debuginject三种情况</u>-->*

debuginject 8 i ./bin/testinject/inject_test1.lua

debuginject 8 di ./bin/testinject/inject_test1.lua

--在cluster中测试 ，单独开出一个debuginject进程，用以访问其他进程中的newservice

<!--不能先inject后立马debug--现在的问题-->

--debug_console.lua 内部进行修改   ：：：先运行debug address    然后在运行debuginject address -d(-di)(i) filename    这些命令就可以运行

<!--.与 : 的区别：-->调用table中函数 .可以传值，如果用：就会出现传值错误

--inject --lua代码.lua步骤 : debug_console.lua-inject ->debug.lua-RUN->inject.lua

--将所有更改成debug1 debug_console1 inject1

--debug--lua指令步骤：debug_console.lua-debug->debug_agent.lua-start->debug.lua-REMOTEDEBUG->remotedebug.lua-M.start(remotedebug.debug_hook()函数，进行输入命令判断)

# 2.最终目标

**进入通过debug address后，输入print("aaa")可以使这个嵌入到正在运行的service中**

热更新如何处理旧的数据，还有闭包的upvalue的有效性问题怎么解决。这时候强大的Lua debug api上场了，调用debug库的**getlocal**函数可以访问任何活动状态的局部变量，**getupvalue**函数可以访问Lua函数的upvalues，还有相对应的修改函数。

例如，这是查询和修改函数局部变量写的debug函数：

`-- 查找函数的local变量`
`function get_local( func, name )`
    `local i=1`
    `local v_name, value`
    `while true do`
        `v_name, value = debug.getlocal(func,i)`
        `if not v_name or v_name == name then`
            `break`
        `end`
        `i = i+1`
    `end`
    `if v_name and v_name == name then`
        `return value`
    `end`
    `return nil`
`end`
`-- 修改函数的local变量`
`function set_local( func, name, value )`
    `local i=1`
    `local v_name`
    `while true do`
        `v_name, _ = debug.getlocal(func,i)`
        `if not v_name or v_name == name then`
            `break`
        `end`
        `i = i+1`
    `end`
    `if not v_name then`
        `return false`
    `end`
    `debug.setlocal(func,i,value)`
    `return true`
`end`

<!--可以将热更函数进行封装下，然后通过debug输入命令，如果命令存在，则对指定的函数地址进行内容替换-->  https://www.cnblogs.com/losophy/p/9204036.html和https://www.cnblogs.com/RainRill/p/8940673.html明天尝试下 将其进行封装，然后通过debug的调用来执行。。。。*****

signal address查询死循环出现的地方































































https://blog.codingnow.com/2015/02/skynet_debugger.html --debug_console.lua 中的debug 直接输入lua代码

//watch命令  debug address 进入debug调试进入后出现address>可以运行想运行的lua代码或者指令，如果想退出当前使用cont命令，从新进入调试状态



`function CMD.start(address, fd)`
	`assert(channel == nil, "start more than once")`
	`skynet.error(string.format("Attach to :%08x", address))`
	`local handle`
	`channel, handle = debugchannel.create()`
	`local ok, err = pcall(skynet.call, address, "debug", "REMOTEDEBUG", fd, handle)`
	`if not ok then`
		`skynet.ret(skynet.pack(false, "Debugger attach failed"))`
	`else`
		`-- todo hook`
		`skynet.ret(skynet.pack(true))`
	`end`
	`skynet.exit()`
`end`



**skynet: cluster**

1.通过多个skynet(1个master，2个cluster)，形成一个cluster，实现多个进程之间的通信。

2.每个skynet里创建多个newservice，每个newservice实现通信，利用profile实现多个newservice运行时候所占用的cpu和内存情况。

3.将各cluster里面的各newservice运行时使用的cpu和内存情况传输到master，实现监控各newservice运行时的情况。发送数据使用skynet.send()实现只发送不请求



**skynet:inject**

--难点是inject代码的书写

if not  _P then
	print("fixhot,no _P define")
	return
end
--获取函数变量
local function getup(f)
	local  = {}
	if not f then
		return u
	end
	local i = 1
	while true do
		local name,value = debug.getupvalue(f,i)
		if name == nil then
			return u
		end
		u[name] == value
		i = i + 1
	end
	return u
end
--获取原来函数地址和函数变量
local  M = _P.lua.CMD--CMD为原函数的一个表
local getu = getup(M.do_test)--M.do_test是原函数
local test = getu.test
M.do_test = function(msg)
	test("New"..msg)
end

1.在启动newservice里面启动skynet.newservice("debug_console",8000),实现端口监控，通过打开debug控制台，实现热更。

2.通过在控制台下面输入list 查看各lua虚拟机的address，利用address实现热更



**skynet:debug_console**

1.开启debug_console,通过各种命令查看运行中各lua虚拟机运行情况.

**修改debug_console指令，添加代码**

1.  添加一个借口 在service/debug_console.lua 的COMMAND.help的table添加指令代码，并在launch.lua里添加接口实现
2.  使用skynet.info_func(function() return "myinject" end)--返回消息

