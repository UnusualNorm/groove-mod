#pragma once
#include "incomplete.hpp"
#include "scene.hpp"
namespace game {
class SceneHungry : public Scene {
public:
  void spawnFlower(Thread *thread, int ticks);
};
} // namespace game
