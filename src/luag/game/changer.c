// clang-format off
#include "../../game.h"
#include "../luag.h"

extern void Changer_ChangeInstant(void *, void *, int);
extern void Changer_Construct(void *, void *, void *);
extern void Changer_Destruct(void *);

luaG_nil_caller(changer_change_instant, Changer_ChangeInstant(lua_touserdata(L, 1), lua_touserdata(L, 2), lua_tointeger(L, 3)));
luaG_nil_caller(changer_delete, {
  Changer_Destruct(lua_touserdata(L, 1));
  free(lua_touserdata(L, 1));
});
luaG_ptr_caller(changer_new, ({
    void *changer = malloc(0x3a68);
    Changer_Construct(changer, lua_touserdata(L, 1), lua_touserdata(L, 2));
    changer;
}));

void luaG_open_game_changer(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Changer", #name, changer_##name)
  REGISTER(change_instant);
  REGISTER(delete);
  REGISTER(new);
#undef REGISTER
}
