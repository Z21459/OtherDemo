--����ģ��
--require("<ģ����>")   require("<ģ����>")

require("module")

print(module.constant)

module.func2()

--c����Lua���
local path = "usr/local/lua/lib/libluasocket.so"--�����·��
local f = assert(loadlib(path,"luaopen_socket"))--��ʼ������
f()
