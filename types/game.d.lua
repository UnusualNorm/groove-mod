---@meta
---@class game
game = {}
---@class game.LuaValue
---@field state any
---@field index integer
game.LuaValue = {}

---@class game.Anim
game.Anim = {}
---@param name string
---@param recursive integer
---@return game.Anim
function game.Anim:findChild(name, recursive) end

---@param name string
---@return boolean
function game.Anim:playAction(name) end


---@class game.Audio
---@field unknown any
game.Audio = {}
---@param volume number
---@param ticks integer
function game.Audio:fade(volume, ticks) end


---@class game.Changer
---@field unknown any
---@overload fun(arg1: game.Stage, arg2: game.Scene): game.Changer
game.Changer = {}
---@param arg1 game.Thread
---@param arg2 integer
function game.Changer:changeInstant(arg1, arg2) end

---@param L any
function game.Changer:deleteObject(L) end


---@class game.Holder
---@field unknown any
game.Holder = {}
function game.Holder:release() end

---@return game.Scene
function game.Holder:get() end

---@param L any
function game.Holder:deleteObject(L) end


---@class game.HolderCustom : game.Holder
---@field scene game.Scene
---@overload fun(scene: game.Scene): game.HolderCustom
game.HolderCustom = {}
function game.HolderCustom:release() end

---@return game.Scene
function game.HolderCustom:get() end


---@class game.IStage
---@field unknown any
game.IStage = {}
function game.IStage:unknown00() end

function game.IStage:unknown18() end

function game.IStage:unknown20() end

function game.IStage:unknown28() end

function game.IStage:unknown30() end

function game.IStage:unknown38() end

function game.IStage:unknown40() end

function game.IStage:unknown48() end

function game.IStage:unknown50() end

function game.IStage:unknown58() end

function game.IStage:unknown60() end

function game.IStage:unknown68() end

function game.IStage:unknown70() end

function game.IStage:unknown78() end

function game.IStage:unknown80() end

function game.IStage:unknown88() end


---@class game.Ratings
---@field name string
---@field usePercentageThresholds integer
---@field deferPositiveComment integer
---@field countSlipsAsMisses integer
---@field suppressNonnegativeComment integer
---@field suppressNonpositiveComment integer
---@field unknown integer
---@field positiveThreshold integer
---@field negativeThreshold integer
---@field unknown2 any
game.Ratings = {}
---@param argument game.LuaValue
---@return game.Ratings
function game.Ratings.newLua(argument) end

---@param ratings game.Ratings
function game.Ratings.deleteLua(ratings) end


---@class game.Runner
---@field threads game.Thread
---@field unknown any
game.Runner = {}
---@param thread game.Thread
function game.Runner:appendThread(thread) end


---@class game.UnknownStageBase1
---@field runner game.Runner
---@field sequenceId integer
---@field unknown any
game.UnknownStageBase1 = {}

---@class game.UnknownStageBase2
---@field runner game.Runner
---@field owner game.Stage
---@field threadIndex integer
---@field unknown any
game.UnknownStageBase2 = {}

---@class game.UnknownStageBase3
---@field unknown any
game.UnknownStageBase3 = {}

---@class game.Stage : game.IStage, game.UnknownStageBase1, game.UnknownStageBase2, game.UnknownStageBase3
---@field unknown any
game.Stage = {}
function game.Stage:unknown28() end

function game.Stage:unknown30() end

function game.Stage:unknown40() end

function game.Stage:unknown48() end

function game.Stage:unknown58() end

function game.Stage:unknown70() end

function game.Stage:unknown90() end

function game.Stage:unknown98() end

function game.Stage:unknownA0() end

function game.Stage:unknownA8() end

function game.Stage:unknownB0() end

function game.Stage:unknownB8() end

function game.Stage:unknownC0() end

function game.Stage:unknownC8() end

function game.Stage:unknownD0() end

function game.Stage:unknownD8() end

function game.Stage:unknownE0() end

---@return game.Sequence
function game.Stage:getSequence() end

---@param thread game.Thread
---@param ticks integer
---@param mode integer
---@param argument integer
function game.Stage:bopAnim(thread, ticks, mode, argument) end

function game.Stage:disablePause() end

function game.Stage:enablePause() end

function game.Stage:endGameplay() end

---@param ticks integer
---@param alpha number
function game.Stage:fadeScreen(ticks, alpha) end

function game.Stage:finishGameplaySession() end

---@param mode integer
function game.Stage:initGameplay(mode) end

---@param id integer
---@param mode integer
function game.Stage:initSm(id, mode) end

---@param id integer
function game.Stage:prepareSm(id) end

---@param name string
function game.Stage:setComment(name) end

---@param message string
---@param graph string
---@param ratings game.Ratings
---@param mask integer
---@param name string
---@param from string
function game.Stage:setEpilogueAndRatings(message, graph, ratings, mask, name, from) end

function game.Stage:startGameplay() end

function game.Stage:toResults() end

function game.Stage:unk7100138d20() end

---@param thread game.Thread
---@param ticks integer
---@param mode integer
---@return integer
function game.Stage:waitAudioReady(thread, ticks, mode) end

---@param thread game.Thread
---@param mode integer
---@param ticks integer
function game.Stage:waitReady(thread, mode, ticks) end

---@param volume number
---@param speed number
---@param thread game.Thread
---@param id integer
---@param ticks integer
---@param mode integer
function game.Stage:playBgm(volume, speed, thread, id, ticks, mode) end


---@class game.UnknownSceneBase1
---@field unknown any
game.UnknownSceneBase1 = {}
function game.UnknownSceneBase1:unknown10() end

function game.UnknownSceneBase1:unknown18() end


---@class game.UnknownSceneBase2
---@field runner game.Runner
---@field sequenceInfoId integer
---@field unknown any
game.UnknownSceneBase2 = {}

---@class game.UnknownSceneBase3
---@field runner game.Runner
---@field owner game.Scene
---@field threadIndex integer
---@field unknown any
game.UnknownSceneBase3 = {}

---@class game.UnknownSceneBase4
---@field unknown any
game.UnknownSceneBase4 = {}

---@class game.UnknownSceneBase5
game.UnknownSceneBase5 = {}
function game.UnknownSceneBase5:unknown() end


---@class game.UnknownSceneBase6
---@field unknown any
game.UnknownSceneBase6 = {}

---@class game.Scene : game.IStage, game.UnknownSceneBase1, game.UnknownSceneBase2, game.UnknownSceneBase3, game.UnknownSceneBase4, game.UnknownSceneBase5, game.UnknownSceneBase6
---@field unknown1 any
---@field stage game.Stage
---@field unknown2 any
game.Scene = {}
function game.Scene:unknown00() end

function game.Scene:unknown28() end

function game.Scene:unknown30() end

function game.Scene:unknown40() end

function game.Scene:unknown48() end

function game.Scene:unknown58() end

function game.Scene:unknown60() end

function game.Scene:unknown68() end

function game.Scene:unknown70() end

function game.Scene:unknown90() end

function game.Scene:unknown98() end

function game.Scene:unknownA0() end

function game.Scene:unknownA8() end

function game.Scene:unknownB0() end

function game.Scene:unknownB8() end

function game.Scene:unknownC0() end

function game.Scene:unknownC8() end

function game.Scene:unknownD0() end

function game.Scene:unknownD8() end

function game.Scene:unknownE0() end

function game.Scene:unknownE8() end

function game.Scene:unknownF0() end

function game.Scene:unknownF8() end

function game.Scene:unknown100() end

function game.Scene:unknown108() end

function game.Scene:unknown110() end

function game.Scene:unknown118() end

function game.Scene:unknown120() end

function game.Scene:unknown128() end

function game.Scene:unknown130() end

function game.Scene:unknown138() end

---@param child game.Scene
function game.Scene:attachChild(child) end

---@param active integer
function game.Scene:setActive(active) end

---@param enabled integer
function game.Scene:setInputEnabled(enabled) end

---@return game.SceneBasic
function game.Scene:asSceneBasic() end

---@return game.SceneFlydisc
function game.Scene:asSceneFlydisc() end

---@return game.SceneHungry
function game.Scene:asSceneHungry() end

---@return game.SceneParasol
function game.Scene:asSceneParasol() end

---@return game.SceneRing
function game.Scene:asSceneRing() end

---@return game.SceneRope
function game.Scene:asSceneRope() end

---@param L any
function game.Scene:deleteObject(L) end


---@class game.SceneBasic : game.Scene
---@field unknown any
---@overload fun(arg1: game.Stage, arg2: any, arg3: integer): game.SceneBasic
game.SceneBasic = {}
function game.SceneBasic:unknown140() end

---@param arg1 game.Scene
function game.SceneBasic:attachChild(arg1) end

function game.SceneBasic:detachChild() end

function game.SceneBasic:unknown158() end

function game.SceneBasic:unknown160() end

function game.SceneBasic:unknown168() end

function game.SceneBasic:unknown170() end

function game.SceneBasic:unknown178() end


---@class game.SceneFlydisc : game.Scene
---@field unknown any
---@field anim game.Anim
---@field unknown2 any
---@field audio game.Audio
---@field unknown3 any
game.SceneFlydisc = {}
---@param name string
function game.SceneFlydisc:changeBackground(name) end

---@param name string
function game.SceneFlydisc:setBackground(name) end

---@param first integer
---@param second integer
function game.SceneFlydisc:setCountState(first, second) end

---@param thread game.Thread
---@param ticks integer
---@param a integer
---@param b integer
---@param mode integer
function game.SceneFlydisc:throwDisc(thread, ticks, a, b, mode) end


---@class game.SceneHungry : game.Scene
game.SceneHungry = {}
---@param thread game.Thread
---@param ticks integer
function game.SceneHungry:spawnFlower(thread, ticks) end


---@class game.SceneParasol : game.Scene
game.SceneParasol = {}
---@param thread game.Thread
---@param a integer
---@param b integer
---@param c integer
---@param d integer
function game.SceneParasol:open(thread, a, b, c, d) end

---@param thread game.Thread
---@param a integer
---@param b integer
function game.SceneParasol:openAll(thread, a, b) end


---@class game.SceneRing : game.Scene
game.SceneRing = {}
---@param thread game.Thread
---@param ticks integer
function game.SceneRing:hoop(thread, ticks) end


---@class game.SceneRope : game.Scene
game.SceneRope = {}
---@param thread game.Thread
---@param ticks integer
---@param a integer
---@param b integer
function game.SceneRope:doubleUnder(thread, ticks, a, b) end

---@param thread game.Thread
---@param ticks integer
---@param mode integer
function game.SceneRope:jump(thread, ticks, mode) end


---@class game.Sequence
game.Sequence = {}
---@param arg1 integer
---@param arg2 any
function game.Sequence:setNext(arg1, arg2) end


---@class game.StageBasic : game.Stage
---@field render any
---@field ownedScene game.SceneBasic
---@field scene game.SceneBasic
---@overload fun(arg1: game.Sequence, arg2: integer, arg3: integer, arg4: integer, arg5: integer, arg6: integer, arg7: integer): game.StageBasic
game.StageBasic = {}
function game.StageBasic:unknown90() end

---@param arg1 game.Thread
---@return integer
function game.StageBasic:runCategory(arg1) end


---@class game.StageRemix : game.Stage
---@field unknown any
---@field activeScene game.Scene
---@field render any
---@field unknown2 any
---@overload fun(arg1: game.Sequence, arg2: integer, arg3: integer, arg4: integer, arg5: integer, arg6: integer): game.StageRemix
game.StageRemix = {}
function game.StageRemix:unknown28() end

function game.StageRemix:unknown90() end

function game.StageRemix:unknownD8() end

function game.StageRemix:unknownE0() end

function game.StageRemix:unknownE8() end

---@param arg1 integer
---@param arg2 integer
---@return game.Holder
function game.StageRemix:getScene(arg1, arg2) end

---@return integer
function game.StageRemix:getSceneCount() end

function game.StageRemix:unknown100() end

function game.StageRemix:unknown108() end

function game.StageRemix:unknown110() end

---@param index integer
function game.StageRemix:decrementSceneCueCount(index) end

---@param index integer
function game.StageRemix:incrementSceneCueCount(index) end

---@param index integer
---@param argument integer
---@param mode integer
function game.StageRemix:initScene(index, argument, mode) end

---@param value integer
function game.StageRemix:setAllSceneCarryover(value) end

---@param ticks integer
function game.StageRemix:setAllSceneCarryoverTicks(ticks) end

---@param thread game.Thread
---@param index integer
---@return integer
function game.StageRemix:setCueScene(thread, index) end

---@param open integer
function game.StageRemix:setInitParasolOpen(open) end

---@param index integer
---@param value integer
function game.StageRemix:setSceneCarryover(index, value) end

---@param thread game.Thread
---@param index integer
---@param mode integer
function game.StageRemix:waitSceneReady(thread, index, mode) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneBacteria(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneBirds(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneBrush(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneCars(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneClap(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneCooking(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneCrab(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneDancer(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.SceneFlydisc
function game.StageRemix:createSceneFlydisc(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneGrasp(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneGuardian(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneHammer(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.SceneHungry
function game.StageRemix:createSceneHungry(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneHurdle(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneInsect(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneKaeru(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneMoon(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.SceneParasol
function game.StageRemix:createSceneParasol(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createScenePumpup(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createScenePutilabo(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.SceneRing
function game.StageRemix:createSceneRing(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneRolling(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.SceneRope
function game.StageRemix:createSceneRope(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneSamurai(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneShinkai(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneSoccer(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneSoftCatch(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneTalk(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneTheA(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneThunder(arg1, arg2) end

---@param arg1 game.Stage
---@param arg2 integer
---@return game.Scene
function game.StageRemix:createSceneWiper(arg1, arg2) end


---@class game.UnknownThreadBase1
---@field next game.Thread
---@field unknown any
game.UnknownThreadBase1 = {}
function game.UnknownThreadBase1:unknown10() end

function game.UnknownThreadBase1:unknown18() end


---@class game.UnknownThreadBase2
game.UnknownThreadBase2 = {}

---@class game.Thread : game.UnknownThreadBase1, game.UnknownThreadBase2
---@field unknown any
---@field index integer
---@field unknown2 any
---@overload fun(arg1: game.Runner, arg2: integer, arg3: any, arg4: any, arg5: game.Thread): game.Thread
game.Thread = {}
function game.Thread:unknown10() end

function game.Thread:unknown18() end

---@return boolean
function game.Thread:getStopRequested() end

---@param ticks integer
function game.Thread:wait(ticks) end

---@param runner game.Runner
---@param index integer
---@param name string
---@param argument game.LuaValue
---@param parent game.Thread
---@return game.Thread
function game.Thread.newLua(runner, index, name, argument, parent) end


