hk.diag.hkLogSink("cues2")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type StageRemix
local stage = argument.stage
---@type Holder[]
local holders = argument.holders

local function scene()
    ---@type SceneFlydisc
    return Holder.get(holders[3])
end

Thread.wait(thread, 8640)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 2)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneFlydisc.throw_disc(scene(), thread, 0, 3360, -1, false)

Thread.wait(thread, 15360)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 2)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneFlydisc.throw_disc(scene(), thread, 0, 3360, -1, false)

Thread.wait(thread, 23040)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 2)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "basic")
SceneFlydisc.throw_disc(scene(), thread, 0, 3360, -1, false)

Thread.wait(thread, 34560)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 2)
if Thread.get_stop_requested(thread) then return end
Stage.set_comment(stage, "must")
SceneFlydisc.throw_disc(scene(), thread, 0, 3360, -1, false)

Thread.wait(thread, 7680)
if Thread.get_stop_requested(thread) then return end
