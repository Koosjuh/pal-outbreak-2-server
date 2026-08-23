# 0x005ac380 screen_gfx_reset

| field | value |
|---|---|
| Original address | 0x005ac380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac380 |
| Resolved name | screen_gfx_reset |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ae310, FUN_006076c0, FUN_00608300, FUN_006088b0
**Callees:** FUN_005c84e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Small teardown helper: resets graphics/render state via FUN_005c84e0 + libgfx thunks (0x1ad290/0x1ad8b0).

## Notes / uncertainty
Graphics teardown helper (FUN_005c84e0 + 001ad290/001ad8b0(1) ext-lib pair, shared with gfx_pipeline_reset). ext-lib arg semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
