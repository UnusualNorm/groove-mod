#pragma once
#include "incomplete.hpp"
#include "stage.hpp"
namespace game {
class StageRemix : public Stage {
public:
  StageRemix(Sequence *, int, unsigned int, int, int, int);
  ~StageRemix() override;
  void unknown28() override;
  void unknown90() override;
  void unknownD8() override;
  void unknownE0() override;
  virtual void unknownE8();
  virtual Holder *getScene(int, unsigned int) = 0;
  virtual int getSceneCount() = 0;
  virtual void unknown100();
  virtual void unknown108();
  virtual void unknown110();
  char unknown[0x888];
  Scene *activeScene;
  Render *render;
  char unknown2[0x50];
  void decrementSceneCueCount(int index);
  void incrementSceneCueCount(int index);
  void initScene(int index, int argument, unsigned char mode);
  void setAllSceneCarryover(int value);
  void setAllSceneCarryoverTicks(int ticks);
  int setCueScene(Thread *thread, int index);
  void setInitParasolOpen(unsigned char open);
  void setSceneCarryover(int index, int value);
  void waitSceneReady(Thread *thread, int index, unsigned int mode);

  Scene *createSceneBacteria(Stage *, unsigned int);
  Scene *createSceneBirds(Stage *, unsigned int);
  Scene *createSceneBrush(Stage *, unsigned int);
  Scene *createSceneCars(Stage *, unsigned int);
  Scene *createSceneClap(Stage *, unsigned int);
  Scene *createSceneCooking(Stage *, unsigned int);
  Scene *createSceneCrab(Stage *, unsigned int);
  Scene *createSceneDancer(Stage *, unsigned int);
  SceneFlydisc *createSceneFlydisc(Stage *, unsigned int);
  Scene *createSceneGrasp(Stage *, unsigned int);
  Scene *createSceneGuardian(Stage *, unsigned int);
  Scene *createSceneHammer(Stage *, unsigned int);
  SceneHungry *createSceneHungry(Stage *, unsigned int);
  Scene *createSceneHurdle(Stage *, unsigned int);
  Scene *createSceneInsect(Stage *, unsigned int);
  Scene *createSceneKaeru(Stage *, unsigned int);
  Scene *createSceneMoon(Stage *, unsigned int);
  SceneParasol *createSceneParasol(Stage *, unsigned int);
  Scene *createScenePumpup(Stage *, unsigned int);
  Scene *createScenePutilabo(Stage *, unsigned int);
  SceneRing *createSceneRing(Stage *, unsigned int);
  Scene *createSceneRolling(Stage *, unsigned int);
  SceneRope *createSceneRope(Stage *, int);
  Scene *createSceneSamurai(Stage *, unsigned int);
  Scene *createSceneShinkai(Stage *, unsigned int);
  Scene *createSceneSoccer(Stage *, unsigned int);
  Scene *createSceneSoftCatch(Stage *, unsigned int);
  Scene *createSceneTalk(Stage *, unsigned int);
  Scene *createSceneTheA(Stage *, unsigned int);
  Scene *createSceneThunder(Stage *, unsigned int);
  Scene *createSceneWiper(Stage *, unsigned int);
};
static_assert(sizeof(StageRemix) == 0x3548);
} // namespace game
