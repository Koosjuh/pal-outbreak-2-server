# 0x001ce4b0 group_slot_free_by_ids

| field | value |
|---|---|
| Original address | 0x001ce4b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce4b0 |
| Resolved name | group_slot_free_by_ids |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce550, FUN_001ce970
**Callees:** FUN_00106b60, FUN_001aa580
**Referenced globals:** 0x36c310 group table (4 x 0x10, byte0=active, +4=roster ptr, +8/+0xc=id pair)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Finds the 4-slot group entry at 0x36c310 whose short@8==param_1 && short@0xc==param_2, frees its ~0xc80 roster buffer and clears the slot.

## Notes / uncertainty
Frees group slot (0x36c310, 4x0x10) matching id1(+8)/id2(+0xc): heap_free+memset 0xc80 of roster_buf+4, clears active + aux bytes +0xa/+0xb. Establishes roster_buf = 4-byte header + 0xc80 body. FUN_001aa580=free assumed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce4b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
