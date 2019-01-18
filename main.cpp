
#include <lua5.3/lua.hpp>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // blocks until lua code finished
    int err = luaL_loadfile(L, "../test.lua") || lua_pcall(L, 0, 0, 0);

    if(err){
        std::string str = lua_tostring(L, -1);
        cout<<"err: "<<str<<endl;
        lua_pop(L, 1);
    }    

    lua_close(L);

    cout<<"-------END-------"<<endl;
    return 0;
}