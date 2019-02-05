#ifdef MINGW
    #include <lua.hpp>
#elif defined(UBUNTU1604)
    #include <lua5.3/lua.hpp>
#endif

#include <iostream>
#include <string>

using namespace std;


static int printMsg(lua_State *L)
{
    cout<<"CALL C FUNC: "<<__FUNCTION__<<endl;
    return 0;
}


int main(int argc, char const *argv[])
{
    /// 1. init
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // reg func
    lua_pushcfunction(L, printMsg);
    lua_setglobal(L, "my_printMsg");

    /// 2. load file
    int stack_size = lua_gettop(L);
    cout<<"stack size BEFORE: "<<stack_size<<endl;

    // blocks until lua code finished
    int err = luaL_loadfile(L, "../test.lua");
    
    stack_size = lua_gettop(L); 
    cout<<"stack size AFTER: "<<stack_size<<endl;

    int type;
    if(1 == stack_size){
        type = lua_type(L, -1);
        cout<<" current type in stack: "<<type<<endl;   // 6 == LUA_TFUNCTION
    }

    /// 3. call lua func in stack
    err = err || lua_pcall(L, 0, 0, 0);

    cout<<"stack size FINAL: "<<stack_size<<endl;
    if(1 == stack_size){
        type = lua_type(L, -1);
        cout<<" current type in stack: "<<type<<endl;   // 0 == LUA_TNIL
    }

    // lua_settop(L, 0);
    // lua_pcall(L, 0, 0, 0);

    if(err){
        std::string str = lua_tostring(L, -1);
        cout<<"err: "<<str<<endl;
        lua_pop(L, 1);
    }    

    lua_close(L);

    cout<<"-------END-------"<<endl;
    return 0;
}