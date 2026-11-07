#pragma once
#include "audio.hpp"
#include "incomplete.hpp"
#include "scene.hpp"
namespace game {
class SceneFlydisc : public Scene {
public:
  void changeBackground(const char *name);
  void setBackground(const char *name);
  void setCountState(unsigned char first, unsigned char second);
  void throwDisc(Thread *thread, int ticks, int a, int b, unsigned char mode);
  char unknown[0x838];
  Anim *anim;
  char unknown2[0x68];
  Audio audio;
  char unknown3[0xe80];
};
static_assert(sizeof(SceneFlydisc) == 0x5158);
} // namespace game
