--����һ��module
module ={}
--����һ������
module.constant = "����һ������"
--����
function module.func1()
	print("һ�����к���")
end

function module.func2()
	print("һ��˽��")
end

function module.func3()
	func2()
end

return module
