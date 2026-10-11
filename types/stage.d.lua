---@meta

---@class Stage
Stage = {}

---@param stage Stage
---@param thread Thread
---@param unk1 integer
---@param unk2 integer
---@param unk3 integer
function Stage.bop_anim(stage, thread, unk1, unk2, unk3) end

---@param stage Stage
function Stage.disable_pause(stage) end

---@param stage Stage
function Stage.enable_pause(stage) end

---@param stage Stage
function Stage.end_gameplay(stage) end

---@param stage Stage
---@param ticks integer
---@param opacity number
function Stage.fade_screen(stage, ticks, opacity) end

---@param stage Stage
function Stage.finish_gameplay_session(stage) end

---@param stage Stage
---@return Render
function Stage.get_render(stage) end

---@param stage Stage
---@return Runner
function Stage.get_runner(stage) end

---@param stage Stage
---@return integer
function Stage.get_thread_index(stage) end

---@param stage Stage
---@param pause_mode boolean
function Stage.init_gameplay(stage, pause_mode) end

---@param stage Stage
---@param song integer
---@param enabled boolean
function Stage.init_sm(stage, song, enabled) end

---@param volume number
---@param pitch number
---@param stage Stage
---@param thread Thread
---@param song integer
---@param start integer
---@param offset integer
function Stage.play_bgm(volume, pitch, stage, thread, song, start, offset) end

---@param stage Stage
---@param song integer
function Stage.prepare_sm(stage, song) end

---@param stage Stage
---@param scene Scene|nil
function Stage.set_active_scene(stage, scene) end

---@param stage Stage
---@param comment string
function Stage.set_comment(stage, comment) end

---@param stage Stage
---@param msbt string
---@param graph string
---@param ratings Ratings
---@param unk1 integer
---@param unk2 string
---@param unk3 string
function Stage.set_epilogue_and_ratings(stage, msbt, graph, ratings, unk1, unk2, unk3) end

---@param stage Stage
function Stage.start_gameplay(stage) end

---@param stage Stage
function Stage.to_results(stage) end

---@param stage Stage
function Stage.unk_7100138d20(stage) end

---@param stage Stage
---@param thread Thread
---@param audio_id integer
---@param align_ticks integer
function Stage.wait_audio_ready(stage, thread, audio_id, align_ticks) end

---@param stage Stage
---@param thread Thread
---@param flag boolean
---@param timeout integer
function Stage.wait_ready(stage, thread, flag, timeout) end
