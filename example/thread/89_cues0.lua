assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("cues0")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")
---@type game.Holder[]
local holders = assert(argument.holders, "not argument.holders")

local function scene()
    return holders[1]:get():asSceneRing()
end

thread:wait(20160)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 0)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(13920)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 0)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(1440)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(7680)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 0)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(10080)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 0)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(7680)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 0)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(18720)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 0)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():hoop(thread, -1)
thread:wait(10080)
if thread:getStopRequested() then return end
