// clang-format off
#include "../../game.h"
#include "../luag.h"

typedef struct HolderCustom HolderCustom;
typedef struct HolderCustomVTable HolderCustomVTable;

struct HolderCustom {
  const HolderCustomVTable *vtable;
  void *scene;
};

struct HolderCustomVTable {
  void (*destroy)(HolderCustom *);
  void (*delete)(HolderCustom *);
  void (*release)(HolderCustom *);
  void *(*get)(HolderCustom *);
};

static void *get(HolderCustom *holder) { return holder->scene; }
static void release(HolderCustom *holder) {
  void *scene = get(holder);
  holder->scene = NULL;
  if (scene != NULL)
    ((void (*)(void *))(*(void ***)scene)[2])(scene);
}
static void destroy(HolderCustom *holder) { release(holder); }
static void custom_delete(HolderCustom *holder) {
  destroy(holder);
  free(holder);
}
static const HolderCustomVTable vtable = {destroy, custom_delete, release, get};

luaG_ptr_caller(holder_custom_new, ({
    HolderCustom *holder = malloc(sizeof(HolderCustom));
    holder->vtable = &vtable;
    holder->scene = lua_touserdata(L, 1);
    holder;
}));
luaG_nil_caller(holder_custom_set, ((HolderCustom *)lua_touserdata(L, 1))->scene = lua_touserdata(L, 2));

void luaG_open_game_holder_custom(lua_State *L) {
#define REGISTER(name)                                                         \
  luaG_register(L, "HolderCustom", #name, holder_custom_##name)
  REGISTER(new);
  REGISTER(set);
#undef REGISTER
}
