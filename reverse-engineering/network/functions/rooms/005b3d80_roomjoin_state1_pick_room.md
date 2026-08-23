# 0x005b3d80 roomjoin_state1_pick_room

| field | value |
|---|---|
| Original address | 0x005b3d80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3d80 |
| Resolved name | roomjoin_state1_pick_room |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3c30
**Callees:** FUN_005b09b0, FUN_005b14b0
**Referenced globals:** 0x6c4634 room-name table; 0x6c4674 room-meta table; 0x6c4a84 selected-room scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+1 sub-state; widget+7 room index; widget+0x18 timer

## Behavioral explanation
Join phase 1: reads the picked room's name/meta from 0x6c4634/0x6c4674 by index, waits for input, and routes to enter (phase 2) or full/locked branches.

## Notes / uncertainty
Phase 1: nav+confirm (mask 0x10), copies meta[idx] to scratch 0x6c4a84, routes on name/meta bytes: named->phase2 enter, empty->phase3 create(sub0), empty-name+meta->phase3 sub4 (locked/pw). sub4 path inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3d80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
