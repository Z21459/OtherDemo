--����ע��-- ����ע�� --[[  ]]--

--[[
print("hello world")
print(type(2))
print(type(2.2))
arr ={"lua","tua"}

for i =0, 2 do
	print(arr[i])
end

arr1 ={}

for i =-2,2 do
	arr1[i] =i*2
end

for i =-2,2 do
	print(arr1[i])
end


for key,value in ipairs(arr)  --������
do
	print(key,value)
end

--ʵ��ƽ��
function squre(iteratorMaxCount,currentNumber)
	if currentNumber<iteratorMaxCount
	then
	currentNumber = currentNumber+1
	return currentNumber,currentNumber*currentNumber
	end
end

for i,n in squre,3,0
do
	print(i,n)
end
]]--


--ͨ�� table��� module package Object(����)
mytable ={}
--�����  concat insert maxn sort remove  #table ����
--���table����
function table_length(t)
	local len =0
	for k,v in ipairs(t)
	do
		len = len + 1
	end
	return len;
end
