assert(thread, "not thread")
assert(argument, "not argument")
hk.diag.hkLogSink("entry")

---@type game.StageRemix
local stage = assert(argument.stage, "not argument.stage")
---@type game.Changer
local changer = assert(argument.changer, "not argument.changer")

stage:fadeScreen(0, 0)
stage:initSm(121, 1)
stage:waitReady(thread, 0, -1)
if thread:getStopRequested() then return end

stage:prepareSm(121)
stage:initGameplay(0)
stage:setInitParasolOpen(0)
stage:initScene(1, -1, 1)
stage:waitSceneReady(thread, 1, 0)
if thread:getStopRequested() then return end

changer:changeInstant(thread, 1)
if thread:getStopRequested() then return end

stage:fadeScreen(480, 1)
stage:waitAudioReady(thread, -1, 0)
if thread:getStopRequested() then return end

thread:wait(480)
if thread:getStopRequested() then return end

stage:enablePause()
stage:playBgm(1, 1, thread, 121, 960, 0)
if thread:getStopRequested() then return end

stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_control", argument, thread))
stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_cues0", argument, thread))
stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_cues1", argument, thread))
stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_cues2", argument, thread))
stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_cues3", argument, thread))
stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_anim", argument, thread))
stage:startGameplay()
thread:wait(960)
if thread:getStopRequested() then return end

stage:unk7100138d20()
thread:wait(91200)
if thread:getStopRequested() then return end

stage:endGameplay()
thread:wait(480)
if thread:getStopRequested() then return end

stage:fadeScreen(1440, 0)
stage:disablePause()
thread:wait(1920)
if thread:getStopRequested() then return end

stage:finishGameplaySession()
if thread:getStopRequested() then return end

stage:toResults()
