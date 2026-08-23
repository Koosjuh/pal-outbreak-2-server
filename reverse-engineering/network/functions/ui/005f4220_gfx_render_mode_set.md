# 0x005f4220 gfx_render_mode_set

| field | value |
|---|---|
| Original address | 0x005f4220 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4220 |
| Resolved name | gfx_render_mode_set |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets a graphics render mode (registered as scene draw callback).

## Notes / uncertainty
Render-mode callback installed in display slot 4 by both screen initializers: gs mode 3 + apply + finalize (3 libgraph imports). GS-register specifics not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
