---@meta

---@class Thread
Thread = {}

---@param thread Thread
---@return boolean
function Thread.get_stop_requested(thread) end

---@param runner Runner
---@param index integer
---@param name string
---@param argument any
---@param parent Thread?
---@return Thread?
function Thread.new(runner, index, name, argument, parent) end

---@param thread Thread
---@param ticks integer
function Thread.wait(thread, ticks) end

---@type Thread?
thread = nil

---@type any
argument = nil
