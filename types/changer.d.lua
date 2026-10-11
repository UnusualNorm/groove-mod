---@meta

---@class Changer
Changer = {}

---@param changer Changer
---@param thread Thread
---@param idx integer
function Changer.change_instant(changer, thread, idx) end

---@param changer Changer
function Changer.delete(changer) end

---@param stage Stage
---@param scene Scene
---@return Changer
function Changer.new(stage, scene) end
