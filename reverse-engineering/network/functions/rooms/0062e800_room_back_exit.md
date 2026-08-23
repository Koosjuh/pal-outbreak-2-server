# 0x0062e800 room_back_exit

| field | value |
|---|---|
| Original address | 0x0062e800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e800 |
| Resolved name | room_back_exit |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062e3c0
**Callees:** FUN_005aec20, FUN_005b68e0, FUN_005b6900, FUN_005c0750
**Referenced globals:** 0x6c4fd5 flag; 0x6c4b9e/9f/ba0/ba1 lobby substates; 0x6c5530 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 sub-state; struct+0x42b screen(=0x19); 0x6c4b90 block

## Behavioral explanation
Back/cancel from room (struct+0x10): sets screen +0x42b=0x19, sends via FUN_005c0750(0x62f3f0); on completion resets 0x6c4b90 block (b9e=1, timer 0x6c5530=0x708).

## Notes / uncertainty
REWROTE from shallow 'classified' to full reconstruction. Back-out SM: sends op0x70 (FUN_005c0750, cb 0x62f3f0), then re-arms lobby block to room-list (0x6c4b9e lobby_sm=1, screen_major/step=0, timer 0x6c5530=0x708) via FUN_005aec20. Contrast 0062e8e0 which sets lobby_sm=3.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
