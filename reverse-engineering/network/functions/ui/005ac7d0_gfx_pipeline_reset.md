# 0x005ac7d0 gfx_pipeline_reset

| field | value |
|---|---|
| Original address | 0x005ac7d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac7d0 |
| Resolved name | gfx_pipeline_reset |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_006069b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Resets render pipeline via ext lib thunks (0x1ad290/0x1ad8b0/0x1d3fd0/0x1d41c0).

## Notes / uncertainty
Render-pipeline reset via 4 ext-lib thunks (001ad290/001ad8b0(1)/001d3fd0(0,0,0)/001d41c0). Precise gfx-lib API/args inferred from context.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac7d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
