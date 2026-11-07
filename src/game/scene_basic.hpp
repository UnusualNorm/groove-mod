#pragma once
#include "incomplete.hpp"
#include "scene.hpp"
namespace game {
class SceneBasic : public Scene {
public:
  SceneBasic(Stage *, Render *, char);
  virtual void unknown140();
  virtual void attachChild(Scene *);
  virtual void detachChild();
  virtual void unknown158();
  virtual void unknown160();
  virtual void unknown168();
  virtual void unknown170();
  virtual void unknown178();
  char unknown[0x18];
};
static_assert(sizeof(SceneBasic) == 0x3898);
} // namespace game
