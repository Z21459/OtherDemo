--һ��ģʽ

--�ļ�I/O
file = io.open("hello.lua","r")
--����Ĭ�������ļ�Ϊ
io.input(file)

--�����һ��
print(io.read())

io.close(file)
-- �Ը��ӷ�ʽ��

file1 = io.open("hello.lua","a")
io.output(file1)
--���һ�����ע��
io.write("--�ļ�ע��")
io.close(file1)


--��ȫģʽ��ͬһʱ�䴦�����ļ�   ʹ��file:function_name����io.function_name

file2 = io.open("hello.lua","r")
--�����һ��
print(file2:read())
file2:close()

file3 = io.open("hello.lua","a")
--���һ�����
file3:write("--test")
file3:close()

-- ��ֻ����ʽ���ļ�
file = io.open("hello.lua", "r")

file:seek("end",-25)
print(file:read("*a"))

-- �رմ򿪵��ļ�
file:close()
</pre>
<p>���������Ľ���ǣ�</p>
<pre>
st.lua �ļ�ĩβ--test
