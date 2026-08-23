# 0x001cb010 maybe_call_render_hook

| field | value |
|---|---|
| Original address | 0x001cb010 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cb010 |
| Resolved name | gfx_flush_if_alt_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** func_0x003acd90 (external, likely overlay/library routine)
**Referenced globals:** 0x343575 (mode flag, byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x343575

## Behavioral explanation
Conditional dispatch shim for the graphics/display block, **not** protocol code. It tests a global
byte mode-flag `cRam00343575`; if it equals `1`, it calls an external routine at `0x3ACD90` (an
address in a different overlay/library segment — a display/overlay flush or alternate-path render
entry). Otherwise it does nothing. The same `0x343575` flag gates the teardown path in
gfx_teardown_render_ctx (0x1cb2c0), where the set state also diverts to an external routine
(`0x3acce0`). So `0x343575` selects between the in-module render context path (flag 0) and an
external/overlay-managed path (flag 1); this function is the "if alt-mode, delegate" branch of that
pair. Located in the net-decompile folder only by address adjacency to the transport cluster.

## Input / output
- No parameters, no return (`void`).

## Side effects
- When flag == 1: calls `func_0x003acd90()` (external; its side effects belong to that routine).
- No globals written here.

## Important branches
- `cRam00343575 == 1` → call external `0x3ACD90`.
- else → return (no-op).

## Constants & flags
- `0x00343575` (`cRam00343575`) — display mode flag. `1` = alternate/overlay path (delegate
  externally); other = in-module path (this function does nothing). Same flag drives
  gfx_teardown_render_ctx's external divert.

## Corrected reconstruction
```c
// Graphics-mode dispatch shim (NOT protocol). If alt-render mode is active, delegate to the
// external overlay routine; otherwise do nothing.
void gfx_flush_if_alt_mode(void)
{
    if (g_gfx_mode /* cRam00343575 */ == 1)
        (*(void (*)(void))0x003ACD90)();   // external overlay/render entry
}
```

## Evidence
- Raw decompile lines 5–7: `if (cRam00343575 == 1) func_0x003acd90();`.
- Cross-ref: 0x343575 also gates FUN_001cb2c0 (teardown) toward an external routine (0x3acce0),
  establishing the flag as an in-module-vs-overlay selector.
- Runtime-unvalidated; the external target's exact function is not decompiled here.

## Remaining uncertainty
- What `0x3ACD90` does precisely (overlay flush vs. alt render) is not resolved — it lives outside the
  captured decompile set. Classified `unrelated` to SN@P wire logic.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cb010.c`  — untouched decompiler output.
