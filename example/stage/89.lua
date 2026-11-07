assert(stage, "not stage")
hk.diag.hkLogSink("stage")

---@type game.HolderCustom[]
local holders = {}
for i = 1, 4 do
    holders[i] = game.HolderCustom(nil)
end

local ratings = game.Ratings.newLua({ {
    name = "basic",
    deferPositiveComment = true,
    positiveThreshold = -3,
    negativeThreshold = 9,
}, {
    name = "tech",
    positiveThreshold = -2,
    negativeThreshold = 999,
}, {
    name = "must",
    positiveThreshold = -1,
    negativeThreshold = 999,
}, {
    name = "selfish",
    suppressNonnegativeComment = true,
    positiveThreshold = 0,
    negativeThreshold = 20,
} })

EpilogueStrings = {
    "result_remix_00.msbt",
    "graph/epilogue/remix/type_27",
    "epilogue27",
    "from"
}

stage:setEpilogueAndRatings(
    EpilogueStrings[1],
    EpilogueStrings[2],
    ratings,
    0x3ff,
    EpilogueStrings[3],
    EpilogueStrings[4]
)

local scene = game.SceneBasic(stage, stage.render, "\1")
local changer = game.Changer(stage, scene)
stage.runner:appendThread(game.Thread.newLua(stage.runner, stage.threadIndex, "89_entry", {
    stage = stage,
    changer = changer,
    holders = holders,
}, nil))

function GetSceneCount() return #holders end

function GetScene(idx, unk)
    local holder = holders[idx + 1]
    if not holder then return nil end

    local new_scene = nil
    if idx == 0 then
        new_scene = stage:createSceneRing(stage, 0)
    elseif idx == 1 then
        new_scene = stage:createSceneParasol(stage, 0)
    elseif idx == 2 then
        new_scene = stage:createSceneFlydisc(stage, 0)
    elseif idx == 3 then
        new_scene = stage:createSceneHungry(stage, 0)
    end

    if not new_scene then return nil end
    holder:release()
    holder.scene = new_scene
    return holder
end

function Destroy()
    for i = 1, #holders do
        holders[i]:deleteObject()
    end
    changer:deleteObject()
    scene:deleteObject()
    game.Ratings.deleteLua(ratings)
end
