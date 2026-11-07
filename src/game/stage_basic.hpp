#pragma once
#include "incomplete.hpp"
#include "stage.hpp"
namespace game {
class StageBasic : public Stage {
public:
  StageBasic(Sequence *, int, int, int, int, int, int);
  ~StageBasic() override;
  void unknown90() override;
  int runCategory(Thread *);
  Render *render;
  SceneBasic *ownedScene;
  SceneBasic *scene;
};
static_assert(sizeof(StageBasic) == 0x2c78);
} // namespace game
