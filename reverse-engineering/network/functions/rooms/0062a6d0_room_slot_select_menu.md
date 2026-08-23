# 0x0062a6d0 room_slot_select_menu

| field | value |
|---|---|
| Original address | 0x0062a6d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062a6d0 |
| Resolved name | room_slot_select_menu |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a5e0
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_0062bd50, FUN_0062cf10
**Referenced globals:** 0x7154a1 name-scratch; 0x7154b1 name-scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Room/member-slot selection state machine: cursor at +10 (0..4), memsets/copies the +0x1055 roster+name array, plays SE, advances sub-state.

## Notes / uncertainty
UPGRADED from classified: slot-select menu, cursor 0..4 over 0x25-stride slot array at ctx+0x1045(name)/+0x1055(2nd field, byte0=occupied); picks copy name+field to scratch 0x7154a1/0x7154b1 -> state 4, commit occupied -> state 5, row3=back, row4=OK gate 0062bd50. Held Medium: FUN_005b14b0 mask semantics ambiguous (pad-edge test 0x10/0x20/0x200 vs send-window guard); 0062bd50/0062cf10 roles undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062a6d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
