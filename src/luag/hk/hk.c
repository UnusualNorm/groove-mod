#include "../luag.h"

void luaG_open_hk(lua_State *L) {
  lua_newtable(L);
  lua_setglobal(L, "hk");
  luaG_open_hk_diag(L);
}
