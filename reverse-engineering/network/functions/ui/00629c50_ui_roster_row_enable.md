# 0x00629c50 ui_roster_row_enable

| field | value |
|---|---|
| Original address | 0x00629c50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629c50 |
| Resolved name | ui_roster_row_enable |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20
**Referenced globals:** 0x6c555e player-count; 0x6c5562 per-slot-flag(0xa5)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006c555e

## Behavioral explanation
Widget update callback: enables/positions a roster row only if its slot index (+3) is within the current room player count bRam006c555e, choosing icon 0x82/0x83 by the per-slot flag at 0x6c5562.

## Notes / uncertainty
Per-row roster visibility gate: row shown iff slot(record+3)<bRam006c555e; icon 0x82/0x83 by per-slot flag 0x6c5562 stride 0xa5; state2=teardown. Core to the 1/0p create-room symptom. Icon exact meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629c50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
