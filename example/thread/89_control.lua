assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("control")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")
---@type game.Changer
local changer = assert(argument.changer, "not argument.changer")
---@type game.Holder[]
local holders = assert(argument.holders, "not argument.holders")

local function scene_ring()
    return holders[1]:get():asSceneRing()
end

local function scene_parasol()
    return holders[2]:get():asSceneParasol()
end

local function scene_flydisc()
    return holders[3]:get():asSceneFlydisc()
end

local function scene_hungry()
    return holders[4]:get():asSceneHungry()
end

stage:initScene(0, -1, 0)
stage:initScene(2, -1, 0)
stage:initScene(3, -1, 0)
stage:setAllSceneCarryover(2)
stage:setAllSceneCarryoverTicks(960)
stage:setInitParasolOpen(0)
thread:wait(5760)
if thread:getStopRequested() then return end

stage:setSceneCarryover(1, 1)
changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

thread:wait(480)
if thread:getStopRequested() then return end

-- unk_7100203c60(scene_data, 1)
changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

stage:setCueScene(thread, 1)
if thread:getStopRequested() then return end

thread:wait(480)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 1)
if thread:getStopRequested() then return end

stage:setSceneCarryover(1, 2)
thread:wait(2880)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 2)
if thread:getStopRequested() then return end

scene_flydisc():setBackground("BG_IMG_B")
scene_flydisc():setCountState(1, 0)
thread:wait(4800)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

stage:setSceneCarryover(3, 1)
thread:wait(3840)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

thread:wait(3840)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

stage:setSceneCarryover(3, 1)
thread:wait(2880)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 2)
if thread:getStopRequested() then return end

scene_flydisc():setBackground("BG_IMG_B")
scene_flydisc():setCountState(1, 0)
thread:wait(4800)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

thread:wait(4320)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

thread:wait(3360)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

thread:wait(2400)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 1)
if thread:getStopRequested() then return end

thread:wait(3840)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

thread:wait(1440)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

stage:setSceneCarryover(3, 2)
thread:wait(2400)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 2)
if thread:getStopRequested() then return end

scene_flydisc():setBackground("BG_IMG_B")
scene_flydisc():setCountState(1, 0)
thread:wait(2400)
if thread:getStopRequested() then return end

scene_flydisc().anim:findChild("count_base", 1):playAction("FadeOut")
scene_flydisc().audio:fade(0, 2400)
thread:wait(2880)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

thread:wait(2880)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

thread:wait(4800)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

thread:wait(2880)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 1)
if thread:getStopRequested() then return end

thread:wait(4800)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 3)
if thread:getStopRequested() then return end

thread:wait(11520)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 0)
if thread:getStopRequested() then return end

thread:wait(1920)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 2)
if thread:getStopRequested() then return end

scene_flydisc():setBackground("BG_IMG_B")
thread:wait(5760)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 1)
if thread:getStopRequested() then return end

thread:wait(3840)
if thread:getStopRequested() then return end
