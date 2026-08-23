# 0x001e23dc bswap16_dup

| field | value |
|---|---|
| Original address | 0x001e23dc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e23dc |
| Resolved name | bswap16_dup |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5688, FUN_001eaf30, FUN_001edd9c
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
16-bit byte swap (duplicate of e234c).

## Notes / uncertainty
Duplicate of bswap16 @e234c. Pure.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e23dc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
