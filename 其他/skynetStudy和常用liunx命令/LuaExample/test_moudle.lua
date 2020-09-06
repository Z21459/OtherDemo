--调用模块
--require("<模块名>")   require("<模块名>")

require("module")

print(module.constant)

module.func2()

--c包和Lua结合
local path = "usr/local/lua/lib/libluasocket.so"--库绝对路径
local f = assert(loadlib(path,"luaopen_socket"))--初始化函数
f()
