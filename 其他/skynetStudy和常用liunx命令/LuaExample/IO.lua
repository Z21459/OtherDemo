--一般模式

--文件I/O
file = io.open("hello.lua","r")
--设置默认输入文件为
io.input(file)

--输出第一行
print(io.read())

io.close(file)
-- 以附加方式打开

file1 = io.open("hello.lua","a")
io.output(file1)
--最后一行添加注释
io.write("--文件注释")
io.close(file1)


--完全模式，同一时间处理多个文件   使用file:function_name代替io.function_name

file2 = io.open("hello.lua","r")
--输出第一行
print(file2:read())
file2:close()

file3 = io.open("hello.lua","a")
--最后一行添加
file3:write("--test")
file3:close()

-- 以只读方式打开文件
file = io.open("hello.lua", "r")

file:seek("end",-25)
print(file:read("*a"))

-- 关闭打开的文件
file:close()
</pre>
<p>我这边输出的结果是：</p>
<pre>
st.lua 文件末尾--test
