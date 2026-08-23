# 0x005bc050 inroom_set_player_state_2

| field | value |
|---|---|
| Original address | 0x005bc050 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc050 |
| Resolved name | inroom_set_player_state_2 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005c5120
**Referenced globals:** 0x6ff70d (roster id table, stride 0x114); 0x6ff2b5 (per-player ready-state array)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-event 0x10: finds the roster slot matching the payload id and sets that player's ready/state byte at 0x6ff2b5[i] to 2; sibling of FUN_005bbfc0.

## Notes / uncertainty
Byte-identical sibling of 0x005bbfc0 under dispatcher case 0x10, stores state=2. Semantics of 1 vs 2 unconfirmed on rig.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc050.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
