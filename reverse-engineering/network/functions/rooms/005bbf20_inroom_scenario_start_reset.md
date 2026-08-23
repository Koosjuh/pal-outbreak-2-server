# 0x005bbf20 inroom_scenario_start_reset

| field | value |
|---|---|
| Original address | 0x005bbf20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbf20 |
| Resolved name | inroom_scenario_start_reset |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bdf90, FUN_005c5c10, FUN_005c5c70
**Referenced globals:** 0x6fb758 (0x654 scenario buffer); 0x6ff2b2/0x6ff2af (scenario flags); 0x6c4b90 (game-mode byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b1; cRam006c4b90

## Behavioral explanation
Sub-event 3: when in-room (0x6ff2b1==1), clears scenario/game-start state (0x6ff2b2/0x6ff2af and the 0x654 buffer 0x6fb758) then either enters scenario (FUN_005c5c10 + start FUN_005bdf90(1)) for game-modes 0x04/0x0e or resets to lobby (FUN_005c5c70).

## Notes / uncertainty
op0x13 sub-3 scenario start/reset, gated on 0x6ff2b1==1; modes 4/0xe send op04 create-slot (FUN_005c5c10)+start, else send op10 room-info (FUN_005c5c70). Corrected callee opcodes from PACKET_INDEX.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbf20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
