# 0x005bb1f0 set_line_draw_params

| field | value |
|---|---|
| Original address | 0x005bb1f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb1f0 |
| Resolved name | set_line_draw_params |
| Subsystem | chat |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bb380
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets per-line draw params: maps param(0..3) to a y/offset constant (0x03/0x02/0x01/0x00 -> -0x1e/-0x02/-0x12/-0x22) and calls the draw-mode setters func_0x001ad8b0(1)/func_0x001af0a0.

## Notes / uncertainty
Maps line-kind 0..3 to signed Y offset {0:-34,1:-18,2:-2,3:-30} and programs draw-state via func_0x001ad8b0(1)/001af0a0. Offset table exact; the param being a Y offset vs other draw attr inferred from caller.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb1f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
