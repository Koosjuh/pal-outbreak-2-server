# 0x001cf020 member_list_intersects_active_group_dup

| field | value |
|---|---|
| Original address | 0x001cf020 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf020 |
| Resolved name | member_list_intersects_active_group_dup |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ce360
**Referenced globals:** 0x36c350 entity-table A
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Exact duplicate of FUN_001ce420: scans 0x36c350 and uses FUN_001ce360 to test membership of param_1.

## Notes / uncertainty
Byte-identical dup of FUN_001ce420. Scans 16x0xc group table @0x36c350 (gate active!=0 && flags&4 && obj!=0), tests member-id intersection via FUN_001ce360 (list@+0x808,count@+0x812,stride0x26). Read-only predicate.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
