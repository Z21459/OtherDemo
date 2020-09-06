#include"lua.h"

#include"lauxlib.h"

#include"lualib.h"

int main(int argc, char *argv[])

{

lua_State *L = lua_open();

luaopen_base(L);

luaopen_io(L);

const char *buf = "print('hello, world!')";

lua_dostring(buf); // luaL_dostring(L,buf);原文有问题

lua_close(L);

return 0;

}

//程序输出：hello, world!