%module game
%nodefaultctor;

%{
#include "./utils.hpp"
#include "./extensions.hpp"
#include "../game.h"
#include "../luag/luag.h"
%}

%init %{
    int module = lua_gettop(L);
    lua_pushglobaltable(L);
    int globals = lua_gettop(L);

    lua_pushnil(L);
    while (lua_next(L, module)) {
        lua_pushvalue(L, -2);
        lua_pushvalue(L, -2);
        lua_rawset(L, globals);
        lua_pop(L, 1);
    }

    lua_pop(L, 1);
%}

// TMP
%typemap(out) SWIGTYPE * {
  SWIG_NewPointerObj(L, $1, $descriptor, 0);
  SWIG_arg++;
}

// TMP
// %typemap(in) const char *leakedString {
//     $1 = const_cast<char *>(luaL_checkstring(L, $input));
//     lua_pushvalue(L, $input);
//     luaL_ref(L, LUA_REGISTRYINDEX);
// }
// %apply const char *leakedString {
//     const char *message,
//     const char *graph,
//     const char *name,
//     const char *from
// };

%typemap(in, numinputs=0) lua_State * { $1 = L; }
%typemap(in) swig::LuaValue { $1 = {L, $input}; }

%include "./utils.hpp"
%include "../game.h"

%extend game::Thread {
    static game::Thread *newLua(game::Runner *runner, int index, const char *name, swig::LuaValue argument, game::Thread *parent);
}

%extend game::Ratings {
    static game::Ratings *newLua(swig::LuaValue argument);
    static void deleteLua(lua_State *L, game::Ratings *ratings);
}

%extend game::Scene {
    SWIG_CASTER(SceneBasic)
    SWIG_CASTER(SceneFlydisc)
    SWIG_CASTER(SceneHungry)
    SWIG_CASTER(SceneParasol)
    SWIG_CASTER(SceneRing)
    SWIG_CASTER(SceneRope)
    SWIG_DELETER
}
%extend game::Holder { SWIG_DELETER }
%extend game::Changer { SWIG_DELETER }
