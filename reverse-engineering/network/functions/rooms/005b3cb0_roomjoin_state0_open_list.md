# 0x005b3cb0 roomjoin_state0_open_list

| field | value |
|---|---|
| Original address | 0x005b3cb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3cb0 |
| Resolved name | roomjoin_state0_open_list |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3c30
**Callees:** FUN_005b4c80, FUN_005b6c90, FUN_005b7fd0, FUN_005ba570, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** 0x6c4630 cRam006c4630 room count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x900 phase; struct+0x454 list-active flag; widget+7 selected idx

## Behavioral explanation
Join phase 0: if rooms exist (0x6c4630), opens the room-list picker widget (list 0x5b7fd0 id 0xb, layout 0x5b4c80(9)) and sets active flag +0x454; else marks empty (phase 3).

## Notes / uncertainty
Phase 0: force-flag w[4] or room_count 0x6c4630==0 -> phase 3 (create); else build picker (list id 0xb) -> phase 1. Always ret 0. w[4] force-create source not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3cb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
