# 0x001ce420 roster_id_present_in_any_group

| field | value |
|---|---|
| Original address | 0x001ce420 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce420 |
| Resolved name | roster_id_present_in_any_group |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ce360
**Referenced globals:** 0x36c350 entity-table A (16 x 0xc, byte0=active, byte3=flags, +4=ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans the 16-entry entity table at 0x36c350 (active + flag byte[3]&4) and calls FUN_001ce360 to test whether param_1 (a member/id) exists in any group; returns 1 on first hit.

## Notes / uncertainty
Predicate over entity-table A (0x36c350, 16x0xc): active && flags&0x04 && ptr!=0 -> FUN_001ce360(ptr,id); returns 1 on first hit. Byte-identical dup of FUN_001cf020. extraout_t3 is a decompiler aliasing artifact. FUN_001ce360 internals unread.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
