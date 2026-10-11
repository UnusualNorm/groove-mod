---@meta
---@class SceneFlydisc : Scene
SceneFlydisc = {}

---@param scene SceneFlydisc
---@param background string
function SceneFlydisc.change_background(scene, background) end

---@param scene SceneFlydisc
---@return Anim
function SceneFlydisc.get_anim(scene) end

---@param scene SceneFlydisc
---@return Audio
function SceneFlydisc.get_audio(scene) end

---@param scene SceneFlydisc
---@param background string
function SceneFlydisc.set_background(scene, background) end

---@param scene SceneFlydisc
---@param enabled boolean
---@param unk boolean
function SceneFlydisc.set_count_state(scene, enabled, unk) end

---@param scene SceneFlydisc
---@param thread Thread
---@param color integer
---@param length integer
---@param sound_id integer
---@param unk boolean
function SceneFlydisc.throw_disc(scene, thread, color, length, sound_id, unk) end
