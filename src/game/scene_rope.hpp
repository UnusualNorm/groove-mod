#pragma once
#include "incomplete.hpp"
#include "scene.hpp"
namespace game {
class SceneRope : public Scene {
public:
  void doubleUnder(Thread *thread, int ticks, unsigned int a, unsigned int b);
  void jump(Thread *thread, int ticks, unsigned int mode);
};
} // namespace game
