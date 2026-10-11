hk.diag.hkLogSink("entry")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type StageRemix
local stage = argument.stage
---@type Changer
local changer = argument.changer

Stage.fade_screen(stage, 0, 0)
Stage.init_sm(stage, 121, true)
Stage.wait_ready(stage, thread, false, -1)
if Thread.get_stop_requested(thread) then return end
Stage.prepare_sm(stage, 121)
Stage.init_gameplay(stage, false)
StageRemix.set_init_parasol_open(stage, false)
StageRemix.init_scene(stage, 1, -1, true)
StageRemix.wait_scene_ready(stage, thread, 1, false)
if Thread.get_stop_requested(thread) then return end
Changer.change_instant(changer, thread, 1)
if Thread.get_stop_requested(thread) then return end
Stage.fade_screen(stage, 480, 1)
Stage.wait_audio_ready(stage, thread, -1, 0)
if Thread.get_stop_requested(thread) then return end
Thread.wait(thread, 480)
if Thread.get_stop_requested(thread) then return end
Stage.enable_pause(stage)
Stage.play_bgm(1, 1, stage, thread, 121, 960, 0)
if Thread.get_stop_requested(thread) then return end
local runner = Stage.get_runner(stage)
local thread_index = Stage.get_thread_index(stage)
Runner.append_thread(runner, Thread.new(runner, thread_index, "89_control", argument, thread) or error("not control"))
Runner.append_thread(runner, Thread.new(runner, thread_index, "89_cues0", argument, thread) or error("not cues0"))
Runner.append_thread(runner, Thread.new(runner, thread_index, "89_cues1", argument, thread) or error("not cues1"))
Runner.append_thread(runner, Thread.new(runner, thread_index, "89_cues2", argument, thread) or error("not cues2"))
Runner.append_thread(runner, Thread.new(runner, thread_index, "89_cues3", argument, thread) or error("not cues3"))
Runner.append_thread(runner, Thread.new(runner, thread_index, "89_anim", argument, thread) or error("not anim"))
Stage.start_gameplay(stage)
Thread.wait(thread, 960)
if Thread.get_stop_requested(thread) then return end
Stage.unk_7100138d20(stage)
Thread.wait(thread, 91200)
if Thread.get_stop_requested(thread) then return end
Stage.end_gameplay(stage)
Thread.wait(thread, 480)
if Thread.get_stop_requested(thread) then return end
Stage.fade_screen(stage, 1440, 0)
Stage.disable_pause(stage)
Thread.wait(thread, 1920)
if Thread.get_stop_requested(thread) then return end
Stage.finish_gameplay_session(stage)
if Thread.get_stop_requested(thread) then return end
Stage.to_results(stage)
