# 0x0062bbc0 room_slot_select_menu2

| field | value |
|---|---|
| Original address | 0x0062bbc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062bbc0 |
| Resolved name | room_slot_select_menu2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062ba70
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_0062bd50, FUN_0062cf10
**Referenced globals:** 0x7154a1/0x7154b1 name scratch; +0x1055 roster slot
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Room-slot selection variant with a selection==3 special branch; polls occupancy (FUN_0062bd50), clears scratch (FUN_0062cf10) and copies the +0x1055 name slot.

## Notes / uncertainty
Two-phase slot-select menu; slot-3 special case via FUN_0062bd50 occupancy; captures name/record to 0x7154a1/0x7154b1. FUN_005b14b0 pressed/edge polarity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062bbc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
