# 0x001ce6d0 group_roster_update_by_id

| field | value |
|---|---|
| Original address | 0x001ce6d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce6d0 |
| Resolved name | group_roster_update_by_id |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d2970
**Callees:** FUN_001069a8, FUN_001ce670
**Referenced globals:** 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Finds a group slot by id via FUN_001ce670, copies a 0xc84 roster payload into slot+4, and stores short@10.

## Notes / uncertainty
find_by_id then memcpy 0xc84 (full header+body) into slot->roster_buf and store u16 aux@+0xa; returns found?. Decompiler mangles args (extraout_a3, dup param_3) - intended contract {src,id,aux} inferred; resolve via caller FUN_001d2970.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce6d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
