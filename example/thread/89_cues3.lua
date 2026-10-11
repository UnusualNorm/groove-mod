hk.diag.hkLogSink("cues3")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type StageRemix
local stage = argument.stage
---@type Holder[]
local holders = argument.holders

local function scene()
    ---@type SceneHungry
    return Holder.get(holders[4])
end

Thread.wait(thread, 10920)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 360)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1680)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 6240)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "must")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 7680)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1680)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 240)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 5520)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 240)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 7440)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 240)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 11040)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1440)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 480)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 9600)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 3)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1920)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1920)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 240)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1920)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 240)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1440)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 1920)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 240)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "tech")
SceneHungry.spawn_flower(scene(), thread, 0)

Thread.wait(thread, 12720)
if Thread.get_stop_requested(thread) then return end
