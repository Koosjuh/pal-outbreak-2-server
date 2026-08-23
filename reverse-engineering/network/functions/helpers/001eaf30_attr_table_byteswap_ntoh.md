# 0x001eaf30 attr_table_byteswap_ntoh

| field | value |
|---|---|
| Original address | 0x001eaf30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eaf30 |
| Resolved name | attr_table_byteswap_ntoh |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001e2394, FUN_001e23dc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps an attribute table in place using the opposite-order swap helpers (FUN_001e23dc/FUN_001e2394); count swapped first so entry loop uses host-order count.

## Notes / uncertainty
Mirror of 0x1eaddc; count swapped FIRST => ntoh (deserialize). Uses duplicate bswap helpers (1e23dc/1e2394). No callers recorded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eaf30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
