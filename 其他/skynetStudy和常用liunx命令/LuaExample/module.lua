--定义一个module
module ={}
--定义一个变量
module.constant = "这是一个常量"
--函数
function module.func1()
	print("一个公有函数")
end

function module.func2()
	print("一个私有")
end

function module.func3()
	func2()
end

return module
