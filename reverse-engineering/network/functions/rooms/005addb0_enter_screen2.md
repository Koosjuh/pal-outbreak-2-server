# 0x005addb0 enter_screen2

| field | value |
|---|---|
| Original address | 0x005addb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005addb0 |
| Resolved name | enter_screen2 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ade20
**Callees:** FUN_005af2f0, FUN_005b2470
**Referenced globals:** 0x6c4b90(screen id); 0x6c4b91/0x6c4b9e/0x6c4b9f/0x6c4ba0/0x6c4ba1; 0x6c5497; 0x6c5c46
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4b90

## Behavioral explanation
Enters lobby screen id 2: sets 0x6c4b90=2, resets nav fields 0x6c4b9e/9f/ba0/ba1, snapshots 0x6c5c46->0x6c5497, arms input/timer.

## Notes / uncertainty
Straight-line transition into room-list/roster sub-screen: screen_id(0x6c4b90)=2, resets nav fields, snapshots 0x6c5c46->0x6c5497, arms input (af2f0 0,10) + panel (b2470 3). Uncertainty: meaning of carried byte.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005addb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
