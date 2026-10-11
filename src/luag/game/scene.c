// clang-format off
#include "../../game.h"
#include "../luag.h"

extern void BasicScene_Construct(void *, void *, void *, char);
extern void Scene_AttachChild(void *, void *);
extern void Scene_SetActive(void *, unsigned int);
extern void Scene_SetInputEnabled(void *, unsigned char);

typedef struct {
  void (*unk1)(void *);
  void (*unk2)(void *);
  void *(*delete)(void *);
} VTable;

luaG_nil_caller(scene_attach_child, Scene_AttachChild(lua_touserdata(L, 1), lua_touserdata(L, 2)));
luaG_nil_caller(scene_delete, (*(VTable **)lua_touserdata(L, 1))->delete(lua_touserdata(L, 1)));
luaG_ptr_caller(scene_new_basic, ({
    void *scene = _Znwm(0x3898);
    BasicScene_Construct(scene, lua_touserdata(L, 1), lua_touserdata(L, 2), lua_toboolean(L, 3));
    scene;
}));
luaG_nil_caller(scene_set_active, Scene_SetActive(lua_touserdata(L, 1), lua_toboolean(L, 2)));
luaG_nil_caller(scene_set_input_enabled, Scene_SetInputEnabled(lua_touserdata(L, 1), lua_toboolean(L, 2)));

void luaG_open_game_scene(lua_State *L) {
#define REGISTER(name) luaG_register(L, "Scene", #name, scene_##name)
  REGISTER(attach_child);
  REGISTER(delete);
  REGISTER(new_basic);
  REGISTER(set_active);
  REGISTER(set_input_enabled);
#undef REGISTER
}
