# 0x001d09c0 decode_roster_into_grid20

| field | value |
|---|---|
| Original address | 0x001d09c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d09c0 |
| Resolved name | decode_roster_into_grid20 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d0c00, FUN_001d0c90
**Callees:** FUN_001d06d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Header wrapper: copies id bytes from param_1[0]/param_1[2] into param_2, then calls FUN_001d06d0 to fill the 20-row grid from param_1+4.

## Notes / uncertainty
Header wrapper: dst[0]=id, dst[1]=width from src[0]/src[2], then FUN_001d06d0 fills 20-row display grid from src+4 with glyph caching (state=1). Grid layout +0/+1/+2/+4 cells/+0xfa4 vis/+0x1f44 height confirmed from callee.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d09c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
