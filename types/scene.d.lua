---@meta

---@class Scene
Scene = {}

---@param scene Scene
---@param child Scene
function Scene.attach_child(scene, child) end

---@param scene Scene
function Scene.delete(scene) end

---@param stage Stage
---@param render Render
---@param enabled boolean
---@return Scene
function Scene.new_basic(stage, render, enabled) end

---@param scene Scene
---@param active boolean
function Scene.set_active(scene, active) end

---@param scene Scene
---@param enabled boolean
function Scene.set_input_enabled(scene, enabled) end
