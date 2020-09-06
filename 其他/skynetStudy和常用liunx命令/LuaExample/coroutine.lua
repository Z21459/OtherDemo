--Lua协同程序(coroutine)
--线程与协同程序的主要区别在于，一个具有多个线程的程序可以同时运行几个线程，而协同程序却需要彼此协作的运行。

--在任一指定时刻只有一个协同程序在运行，并且这个正在运行的协同程序只有在明确的被要求挂起的时候才会被挂起。

--协同程序有点类似同步的多线程，在等待同一个线程锁的几个线程有点类似协同。

-- creat  resume yield(挂起) status wrap9调用这个，进入coroutine和creat功能重复)  running(一个coroutine就是一个线程)

co = coroutine.create(
	function(i)
		print(i);
	end
)

coroutine.resume(co,1)--1
print(coroutine.status(co))--dead

co1 = coroutine.wrap(
	function(i)
		print(i)
	end
)
co1(1)

co2 = coroutine.create(
	function()
		for i=1,10 do
		print(i)
		if i ==3 then
			print(coroutine.status(co2))--running
			print(coroutine.running())--thread:xxxxx
		end
		coroutine.yield()
	end
end
)

coroutine.resume(co2)--1
coroutine.resume(co2)--2
coroutine.resume(co2)--3

print(coroutine.status(co2))--suspendedd
print(coroutine.running())

print("----------------------")

--生产者和消费者 使用协同程序
local newProductor

function productor()
	local i=0
	for i = 0,10 do --while true do
		i = i+1
		send(i)--将生产的物品发送给消费者
	end
end

function consumer()
	for i = 0,10 do--while true do
		local i = receiver()--从生产者那里得到物品
		print(i)
	end
end

function receiver()
	local status,value = coroutine.resume(newProductor)
	return value
end

function send(x)
	coroutine.yield(x)--x 表示需要发送的值，值返回以后，就挂起该协同程序
end

--启动程序
newProductor = coroutine.create(productor)
consumer()




