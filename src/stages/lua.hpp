#pragma once
#include "../game/stage_remix.hpp"
#include "../luag/luag.h"

class StageLua : public game::StageRemix {
public:
  lua_State *L;
  StageLua(game::Sequence *a, int b, int c, int d, int e, int f, char *buff,
           long size, const char *name);
  ~StageLua() override;
  game::Holder *getScene(int index, unsigned int argument) override;
  int getSceneCount() override;
};
