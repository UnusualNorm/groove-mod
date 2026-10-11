hk.diag.hkLogSink("anim")
if not thread then error("not thread") end
if not argument then error("not argument") end

---@type StageRemix
local stage = argument.stage

Thread.wait(thread, 17880)
if Thread.get_stop_requested(thread) then return end
Stage.bop_anim(stage, thread, 0, 480, 0)

Thread.wait(thread, 69120)
if Thread.get_stop_requested(thread) then return end
Stage.bop_anim(stage, thread, 0, 480, 1)

Thread.wait(thread, 3840)
if Thread.get_stop_requested(thread) then return end
