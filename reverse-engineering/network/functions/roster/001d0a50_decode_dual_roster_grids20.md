# 0x001d0a50 decode_dual_roster_grids20

| field | value |
|---|---|
| Original address | 0x001d0a50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0a50 |
| Resolved name | decode_dual_roster_grids20 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d0b00, FUN_001d0b90
**Callees:** FUN_001d06d0
**Referenced globals:** 0x528200 roster grid A; 0x5262b0 roster grid B
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Writes header ids then decodes TWO 20-row grids from one payload: FUN_001d06d0 into 0x528200 (param+2) and into 0x5262b0 (param+0x2a).

## Notes / uncertainty
Decodes two 20-row grids from one payload into 0x528200 (recs src+0x08) and 0x5262b0 (recs src+0xA8); same id/width header to both, same base-adjust/region flag reused. Note header width read from src[1] not src[2] (differs from single-grid wrappers) - uncertainty flagged.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
