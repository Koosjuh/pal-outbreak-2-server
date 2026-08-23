# 0x0061e650 ui_gfx_ctx_enter

| field | value |
|---|---|
| Original address | 0x0061e650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e650 |
| Resolved name | ui_gfx_ctx_enter |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0061d6a0, FUN_0061ded0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Paired GS/graphics setup calling two extern gfx primitives (0x1f4630/0x1f5620); menu screen enter.

## Notes / uncertainty
GS draw-context begin: two extern setup primitives func_0x001f4630 then func_0x001f5620, no args. Pure gfx, no net state. Extern primitive exact roles not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
