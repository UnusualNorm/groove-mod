#include "../luag.h"
#include <hk/diag/diag.h>

int hkLogSink(lua_State *L) {
  size_t len;
  const char *msg = lua_tolstring(L, 1, &len);
  hk::diag::hkLogSink(msg, len);
  return 0;
}

extern "C" void luaG_open_hk_diag(lua_State *L) {
  lua_getglobal(L, "hk");
  lua_newtable(L);
  lua_pushcfunction(L, hkLogSink);
  lua_setfield(L, -2, "hkLogSink");
  lua_setfield(L, -2, "diag");
  lua_pop(L, 1);
}
