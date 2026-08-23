# 0x001d09e0 decode_roster_into_grid8

| field | value |
|---|---|
| Original address | 0x001d09e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d09e0 |
| Resolved name | decode_roster_into_grid8 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce740, FUN_001d0a10, FUN_001d0d50, FUN_001d0e90, FUN_001d2970
**Callees:** FUN_001d0510
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Header wrapper: writes id bytes + zero at param_2[0..2], then calls FUN_001d0510 to fill the 8-row grid from param_1+4.

## Notes / uncertainty
8-row sibling; sets dst[2]=0 then FUN_001d0510 fills (cell index col_base+col+row*pitch). Forwarded scalar roles (pitch/base/col-base) inferred from call-site mapping.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d09e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
