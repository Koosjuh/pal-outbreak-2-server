# 0x005bbfc0 inroom_set_player_state_1

| field | value |
|---|---|
| Original address | 0x005bbfc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbfc0 |
| Resolved name | inroom_set_player_state_1 |
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
Sub-event 4: finds the roster slot (0x6ff70d table, stride 0x114) whose id matches the payload and sets that player's ready/state byte at 0x6ff2b5[i] to 1.

## Notes / uncertainty
Dispatcher case 4: scans 0x6ff70d table (stride 0x114) for matching member id, sets 0x6ff2b5[slot]=1. State meaning (ready vs present) inferred from pairing with _2, not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbfc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
