# 0x00614c50 set_draw_context

| field | value |
|---|---|
| Original address | 0x00614c50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614c50 |
| Resolved name | set_draw_context |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614b90
**Callees:** —
**Referenced globals:** iRam0070d1c0+0x1aec0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x1aec0

## Behavioral explanation
Stores the draw-context/env pointer into iRam+0x1aec0 (used by sprite submit path).

## Notes / uncertainty
Stores draw context into +0x1aec0; consumer confirmed (614e60 reads it for submit). Whether ptr vs handle unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614c50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
