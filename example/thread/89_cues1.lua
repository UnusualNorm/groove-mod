hk.diag.hkLogSink("cues1")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type StageRemix
local stage = argument.stage
---@type Holder[]
local holders = argument.holders

local function scene()
    ---@type SceneParasol
    return Holder.get(holders[2])
end

Thread.wait(thread, 1440)
if Thread.get_stop_requested(thread) then return end
StageRemix.increment_scene_cue_count(stage, 1)
StageRemix.set_cue_scene(stage, thread, 1)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "must")
SceneParasol.open(scene(), thread, 720, 1, 0, 0)

Thread.wait(thread, 3840)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "must")
SceneParasol.open(scene(), thread, 720, 0, 0, 0)
StageRemix.decrement_scene_cue_count(stage, 1)

Thread.wait(thread, 33120)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 1)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneParasol.open(scene(), thread, 960, 1, 0, 0)

Thread.wait(thread, 24480)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 1)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneParasol.open(scene(), thread, 960, 1, 0, 0)

Thread.wait(thread, 480)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneParasol.open(scene(), thread, 960, 0, 0, 0)

Thread.wait(thread, 23280)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 1)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "must")
SceneParasol.open(scene(), thread, 720, 1, 0, 0)

Thread.wait(thread, 3120)
if Thread.get_stop_requested(thread) then return end
