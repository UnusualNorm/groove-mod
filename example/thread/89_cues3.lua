assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("cues3")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")
---@type game.Holder[]
local holders = assert(argument.holders, "not argument.holders")

local function scene()
    return holders[4]:get():asSceneHungry()
end

thread:wait(10920)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(360)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(1680)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(6240)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("must")
scene():spawnFlower(thread, 0)
thread:wait(7680)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(1680)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(240)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(5520)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(240)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(7440)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(240)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(11040)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(1440)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(480)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(9600)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 3)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(1920)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(1920)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(240)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(1920)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(240)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(1440)
if thread:getStopRequested() then return end

stage:setComment("basic")
scene():spawnFlower(thread, 0)
thread:wait(1920)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(240)
if thread:getStopRequested() then return end

stage:setComment("tech")
scene():spawnFlower(thread, 0)
thread:wait(12720)
if thread:getStopRequested() then return end
