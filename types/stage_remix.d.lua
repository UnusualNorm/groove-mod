---@meta

---@class StageRemix : Stage
StageRemix = {}

---@type StageRemix?
stage = nil

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_bacteria(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_birds(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_brush(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_cars(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_clap(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_cooking(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_crab(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_dancer(stage, type) end

---@param stage StageRemix
---@param type integer
---@return SceneFlydisc
function StageRemix.create_scene_flydisc(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_grasp(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_guardian(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_hammer(stage, type) end

---@param stage StageRemix
---@param type integer
---@return SceneHungry
function StageRemix.create_scene_hungry(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_hurdle(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_insect(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_kaeru(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_moon(stage, type) end

---@param stage StageRemix
---@param type integer
---@return SceneParasol
function StageRemix.create_scene_parasol(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_pumpup(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_putilabo(stage, type) end

---@param stage StageRemix
---@param type integer
---@return SceneRing
function StageRemix.create_scene_ring(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_rolling(stage, type) end

---@param stage StageRemix
---@param type integer
---@return SceneRope
function StageRemix.create_scene_rope(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_samurai(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_shinkai(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_soccer(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_soft_catch(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_talk(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_the_a(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_thunder(stage, type) end

---@param stage StageRemix
---@param type integer
---@return Scene
function StageRemix.create_scene_wiper(stage, type) end

---@param stage StageRemix
---@param idx integer
function StageRemix.decrement_scene_cue_count(stage, idx) end

---@param stage StageRemix
---@param idx integer
function StageRemix.increment_scene_cue_count(stage, idx) end

---@param stage StageRemix
---@param idx integer
---@param option integer
---@param enabled boolean
function StageRemix.init_scene(stage, idx, option, enabled) end

---@param stage StageRemix
---@param type integer
function StageRemix.set_all_scene_carryover(stage, type) end

---@param stage StageRemix
---@param ticks integer
function StageRemix.set_all_scene_carryover_ticks(stage, ticks) end

---@param stage StageRemix
---@param thread Thread
---@param idx integer
function StageRemix.set_cue_scene(stage, thread, idx) end

---@param stage StageRemix
---@param open boolean
function StageRemix.set_init_parasol_open(stage, open) end

---@param stage StageRemix
---@param idx integer
---@param type integer
function StageRemix.set_scene_carryover(stage, idx, type) end

---@param stage StageRemix
---@param thread Thread
---@param idx integer
---@param unk boolean
function StageRemix.wait_scene_ready(stage, thread, idx, unk) end
