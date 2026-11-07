#pragma once
#include "incomplete.hpp"
#include "scene.hpp"
namespace game {
class SceneRing : public Scene {
public:
  void hoop(Thread *thread, int ticks);
};
} // namespace game
