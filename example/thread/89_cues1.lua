assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("cues1")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")
---@type game.Holder[]
local holders = assert(argument.holders, "not argument.holders")

local function scene()
    return holders[2]:get():asSceneParasol()
end

thread:wait(1440)
if thread:getStopRequested() then return end

stage:incrementSceneCueCount(1)
stage:setCueScene(thread, 1)
if thread:getStopRequested() then return end

stage:setComment("must")
scene():open(thread, 720, 1, 0, 0)
thread:wait(3840)
if thread:getStopRequested() then return end

stage:setComment("must")
scene():open(thread, 720, 0, 0, 0)
stage:decrementSceneCueCount(1)
thread:wait(33120)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 1)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():open(thread, 960, 1, 0, 0)
thread:wait(24480)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 1)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():open(thread, 960, 1, 0, 0)
thread:wait(480)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():open(thread, 960, 0, 0, 0)
thread:wait(23280)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 1)
if thread:getStopRequested() then return end

stage:setComment("must")
scene():open(thread, 720, 1, 0, 0)
thread:wait(3120)
if thread:getStopRequested() then return end
