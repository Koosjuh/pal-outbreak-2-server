# 0x005c2820 room_slot_select_reset

| field | value |
|---|---|
| Original address | 0x005c2820 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2820 |
| Resolved name | room_slot_select_reset |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe500, FUN_005fe8d0, FUN_0062e8e0
**Callees:** FUN_005bf230
**Referenced globals:** 0x6cfa2c/0x6cfa2e (per room-slot cursor pos, stride 0x144); 0x6cbc84 (state flag); 0x6d2158 (current slot index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cbc84; uRam006d2158

## Behavioral explanation
Zeroes the two cursor/position shorts of room-slot param_1 (0x144-stride table), sets current-slot = param_1, clears the 0x6cbc84 state, then defers to bf230.

## Notes / uncertainty
Selects room-list rec param_1: zeroes cursor shorts rec+0x2c/+0x2e, status 0x6cbc84=0, cur index 0x6d2158=param_1, fires cb via FUN_005bf230. Paired writer of getter FUN_005c2890. Upgraded Medium->High.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2820.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
