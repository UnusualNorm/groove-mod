hk.diag.hkLogSink("control")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type Stage
local stage = argument.stage
---@type Changer
local changer = argument.changer
---@type Holder[]
local holders = argument.holders

local function scene_ring()
    ---@type SceneRing
    return Holder.get(holders[1])
end

local function scene_parasol()
    ---@type SceneParasol
    return Holder.get(holders[2])
end

local function scene_flydisc()
    ---@type SceneFlydisc
    return Holder.get(holders[3])
end

local function scene_hungry()
    ---@type SceneHungry
    return Holder.get(holders[4])
end

StageRemix.init_scene(stage, 0, -1, false)
StageRemix.init_scene(stage, 2, -1, false)
StageRemix.init_scene(stage, 3, -1, false)
StageRemix.set_all_scene_carryover(stage, 2)
StageRemix.set_all_scene_carryover_ticks(stage, 960)
StageRemix.set_init_parasol_open(stage, false)
Thread.wait(thread, 5760)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_scene_carryover(stage, 1, 1)
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 480)
if Thread.get_stop_requested(thread) then return end
-- unk_7100203c60(scene_data, 1)
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_cue_scene(stage, thread, 1)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 480)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 1)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_scene_carryover(stage, 1, 2)
Thread.wait(thread, 2880)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 2)
if Thread.get_stop_requested(thread) then return end
SceneFlydisc.set_background(scene_flydisc(), "BG_IMG_B")
SceneFlydisc.set_count_state(scene_flydisc(), true, false)
Thread.wait(thread, 4800)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_scene_carryover(stage, 3, 1)
Thread.wait(thread, 3840)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 3840)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_scene_carryover(stage, 3, 1)
Thread.wait(thread, 2880)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 2)
if Thread.get_stop_requested(thread) then return end
SceneFlydisc.set_background(scene_flydisc(), "BG_IMG_B")
SceneFlydisc.set_count_state(scene_flydisc(), true, false)
Thread.wait(thread, 4800)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 4320)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 3360)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 2400)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 1)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 3840)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 1440)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
StageRemix.set_scene_carryover(stage, 3, 2)
Thread.wait(thread, 2400)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 2)
if Thread.get_stop_requested(thread) then return end
SceneFlydisc.set_background(scene_flydisc(), "BG_IMG_B")
SceneFlydisc.set_count_state(scene_flydisc(), true, false)
Thread.wait(thread, 2400)
if Thread.get_stop_requested(thread) then return end
local flydisc = scene_flydisc() or error("Flydisc scene missing")
Anim.play_action(
    Anim.find_child(
        SceneFlydisc.get_anim(flydisc),
        "count_base",
        true
    ) or error("not count_base"),
    "FadeOut"
)
Audio.fade(0, SceneFlydisc.get_audio(flydisc), 2400)
Thread.wait(thread, 2880)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 2880)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 4800)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 2880)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 1)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 4800)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 3)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 11520)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 1920)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 2)
if Thread.get_stop_requested(thread) then return end
SceneFlydisc.set_background(scene_flydisc(), "BG_IMG_B")
Thread.wait(thread, 5760)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 1)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 3840)
if Thread.get_stop_requested(thread) then return end
