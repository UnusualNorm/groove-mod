assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("anim")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")

thread:wait(17880)
if thread:getStopRequested() then return end
stage:bopAnim(thread, 0, 480, 0)

thread:wait(69120)
if thread:getStopRequested() then return end
stage:bopAnim(thread, 0, 480, 1)

thread:wait(3840)
if thread:getStopRequested() then return end
