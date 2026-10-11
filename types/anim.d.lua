---@meta

---@class Anim
Anim = {}

---@param anim Anim
---@param name string
---@param recursive boolean
---@return Anim?
function Anim.find_child(anim, name, recursive) end

---@param anim Anim
---@param action string
---@return boolean
function Anim.play_action(anim, action) end
