#pragma once
#include "holder.hpp"
#include "incomplete.hpp"
namespace game {
class HolderCustom : public Holder {
public:
  HolderCustom(Scene *scene);
  ~HolderCustom() override;
  void release() override;
  Scene *get() override;
  Scene *scene;
};
} // namespace game
