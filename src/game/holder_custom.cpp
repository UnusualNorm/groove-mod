#include "holder_custom.hpp"
#include "scene.hpp"

using namespace game;
HolderCustom::HolderCustom(Scene *scene) : scene(scene) {}
HolderCustom::~HolderCustom() { release(); }
void HolderCustom::release() {
  delete scene;
  scene = nullptr;
}
Scene *HolderCustom::get() { return scene; }
