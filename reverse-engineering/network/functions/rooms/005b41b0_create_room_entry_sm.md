# 0x005b41b0 create_room_entry_sm

| field | value |
|---|---|
| Original address | 0x005b41b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b41b0 |
| Resolved name | create_room_entry_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3c30
**Callees:** FUN_005b45f0, FUN_005b47a0, FUN_005b4860, FUN_005b4c80, FUN_005b7fd0, FUN_005ba570, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** 0x6c4630 cRam006c4630 room count; 0x6c4674 room-meta table; 0x6c4a84 selected-room scratch
**Referenced strings:** —
**Referenced opcodes:** 0x04
**State vars:** widget+1 phase; widget+2 subphase; widget+7 room idx; struct+0x43c result/slot

## Behavioral explanation
Join phase 3: create-room flow — 7-state machine driving name/password entry (widgets 0x16/0x17 via 0x5b7fd0, keyboard 0x5b4860) and the create handshake, with retry/timeout via 0x5b47a0.

## Notes / uncertainty
7-phase create-room name/password entry+submit SM; gates on room-meta slot (0x6c4674) and count flag (0x6c4630), writes confirm_result screen+0x43c, submits UI request tags 0x16/0x17 via FUN_005b7fd0. Does NOT emit op04 itself. Which tag=name vs password inferred from ordering, not wire-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b41b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
