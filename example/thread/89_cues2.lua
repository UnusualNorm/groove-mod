assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("cues2")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")
---@type game.Holder[]
local holders = assert(argument.holders, "not argument.holders")

local function scene()
    return holders[3]:get():asSceneFlydisc()
end

thread:wait(8640)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 2)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():throwDisc(thread, 0, 3360, -1, 0)
thread:wait(15360)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 2)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():throwDisc(thread, 0, 3360, -1, 0)
thread:wait(23040)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 2)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():throwDisc(thread, 0, 3360, -1, 0)
thread:wait(34560)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 2)
if thread:getStopRequested() then return end

stage:setComment("must")
scene():throwDisc(thread, 0, 3360, -1, 0)
thread:wait(7680)
if thread:getStopRequested() then return end
