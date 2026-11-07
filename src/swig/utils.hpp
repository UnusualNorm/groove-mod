#pragma once

struct lua_State;
namespace swig {
struct LuaValue {
  lua_State *state;
  int index;
};

#define SWIG_DELETER                                                           \
  void deleteObject(lua_State *L) {                                            \
    delete $self;                                                              \
    luaG_clearpointer(L, 1);                                                   \
  }

#define SWIG_CASTER(type)                                                      \
  game::##type *as##type() { return static_cast<game::##type *>($self); }
} // namespace swig
