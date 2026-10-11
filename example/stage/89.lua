hk.diag.hkLogSink("89")
if not stage then error("not stage") end

local scene = Scene.new_basic(stage, Stage.get_render(stage), true);
local changer = Changer.new(stage, scene);
local runner = Stage.get_runner(stage);
local thread_index = Stage.get_thread_index(stage);

---@type HolderCustom[]
local holders = {}
for i = 1, 4 do
    holders[i] = HolderCustom.new(nil);
end

local ratings = Ratings.new_custom({
    name = "basic",
    defer_positive_comment = true,
    positive_threshold = -3,
    negative_threshold = 9,
}, {
    name = "tech",
    positive_threshold = -2,
    negative_threshold = 999,
}, {
    name = "must",
    positive_threshold = -1,
    negative_threshold = 999,
}, {
    name = "selfish",
    suppress_nonnegative_comment = true,
    positive_threshold = 0,
    negative_threshold = 20,
})

Stage.set_epilogue_and_ratings(
    stage,
    "result_remix_00.msbt",
    "graph/epilogue/remix/type_27",
    ratings,
    0x3ff,
    "epilogue27",
    "from"
);

Runner.append_thread(runner, Thread.new(runner, thread_index, "89_entry", {
    stage = stage,
    changer = changer,
    holders = holders,
}, nil) or error("not entry"));

function GetSceneCount() return #holders end

function GetScene(idx, unk)
    local holder = holders[idx + 1];
    if not holder then return nil end
    local new_scene = nil;
    if idx == 0 then
        new_scene = StageRemix.create_scene_ring(stage, 0);
    elseif idx == 1 then
        new_scene = StageRemix.create_scene_parasol(stage, 0);
    elseif idx == 2 then
        new_scene = StageRemix.create_scene_flydisc(stage, 0);
    elseif idx == 3 then
        new_scene = StageRemix.create_scene_hungry(stage, 0);
    end
    if not new_scene then return nil end
    Holder.release(holder);
    HolderCustom.set(holder, new_scene);
    return holder;
end

function Destroy()
    for i = 1, #holders do
        Holder.destroy(holders[i]);
    end
    Changer.delete(changer);
    Scene.delete(scene);
    Ratings.delete_custom(ratings);
end
