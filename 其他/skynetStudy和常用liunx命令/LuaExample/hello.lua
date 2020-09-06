--单行注释-- 多行注释 --[[  ]]--

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


for key,value in ipairs(arr)  --迭代器
do
	print(key,value)
end

--实现平方
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


--通过 table解决 module package Object(对象)
mytable ={}
--表操作  concat insert maxn sort remove  #table 长度
--获得table长度
function table_length(t)
	local len =0
	for k,v in ipairs(t)
	do
		len = len + 1
	end
	return len;
end
