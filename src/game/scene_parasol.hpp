#pragma once
#include "incomplete.hpp"
#include "scene.hpp"
namespace game {
class SceneParasol : public Scene {
public:
  void open(Thread *thread, int a, int b, int c, int d);
  void openAll(Thread *thread, int a, int b);
};
} // namespace game
