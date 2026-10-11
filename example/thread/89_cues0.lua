hk.diag.hkLogSink("cues0")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type StageRemix
local stage = argument.stage
---@type Holder[]
local holders = argument.holders

local function scene()
    ---@type SceneRing
    return Holder.get(holders[1])
end

Thread.wait(thread, 20160)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 0)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 13920)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 0)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 1440)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 7680)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 0)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 10080)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 0)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 7680)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 0)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 18720)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 0)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneRing.hoop(scene(), thread, -1)

Thread.wait(thread, 10080)
if Thread.get_stop_requested(thread) then return end
