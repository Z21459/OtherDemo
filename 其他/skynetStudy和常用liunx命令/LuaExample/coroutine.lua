--LuaЭͬ����(coroutine)
--�߳���Эͬ�������Ҫ�������ڣ�һ�����ж���̵߳ĳ������ͬʱ���м����̣߳���Эͬ����ȴ��Ҫ�˴�Э�������С�

--����һָ��ʱ��ֻ��һ��Эͬ���������У���������������е�Эͬ����ֻ������ȷ�ı�Ҫ������ʱ��Żᱻ����

--Эͬ�����е�����ͬ���Ķ��̣߳��ڵȴ�ͬһ���߳����ļ����߳��е�����Эͬ��

-- creat  resume yield(����) status wrap9�������������coroutine��creat�����ظ�)  running(һ��coroutine����һ���߳�)

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

--�����ߺ������� ʹ��Эͬ����
local newProductor

function productor()
	local i=0
	for i = 0,10 do --while true do
		i = i+1
		send(i)--����������Ʒ���͸�������
	end
end

function consumer()
	for i = 0,10 do--while true do
		local i = receiver()--������������õ���Ʒ
		print(i)
	end
end

function receiver()
	local status,value = coroutine.resume(newProductor)
	return value
end

function send(x)
	coroutine.yield(x)--x ��ʾ��Ҫ���͵�ֵ��ֵ�����Ժ󣬾͹����Эͬ����
end

--��������
newProductor = coroutine.create(productor)
consumer()




