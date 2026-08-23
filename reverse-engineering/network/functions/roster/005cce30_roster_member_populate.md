# 0x005cce30 roster_member_populate

| field | value |
|---|---|
| Original address | 0x005cce30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cce30 |
| Resolved name | roster_member_populate |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ca0a0, FUN_005ca1a0, FUN_005ca290, FUN_005ca320, FUN_005ca380, FUN_005ca420, FUN_005ca480, FUN_005ca4f0, FUN_005ca5c0
**Callees:** FUN_005d8340, FUN_005dedf0
**Referenced globals:** 0x701068+0x5ffc0 display-list; 0x701068+0x68dd8 member-id array; 0x701068+0x68e28 member-port array; 0x701068+0x68e50 member-slot array; 0x701068+0x60dcf member count; 0x701068+0x60dce flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x60dcf; 0x701070+0x2e; 0x701068+0x60dce

## Behavioral explanation
Roster-fill pass: for each room ('\r') row awaiting a reply (state[5]==1), dequeues the matching record (FUN_005d8340) and writes member id/port/slot into the roster arrays (0x68dd8/0x68e28/0x68e50), incrementing the member count 0x60dcf; drives the sub-state 8/10 and returns done/accept codes.

## Notes / uncertainty
In-room roster-fill pass: walks display-list 0x5ffc0 (500), for each '\r' room row awaiting reply (state[5]==1) dequeues session record (FUN_005d8340) and appends member to arrays 0x68dd8(id)/0x68e28(field)/0x68e50(slot), count 0x60dcf; row state 2(has member)/3(empty); drives sub-state 8/10, -1 one-shot. Control flow exact; rec-field meanings depend on FUN_005d8340 layout (unconfirmed) and op10 slot-dedup (row+0x44 float) purpose unclear. PRIME runtime-trace candidate for the roster-count goal.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cce30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
