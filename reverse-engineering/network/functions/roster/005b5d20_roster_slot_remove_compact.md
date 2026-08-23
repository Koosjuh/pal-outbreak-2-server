# 0x005b5d20 roster_slot_remove_compact

| field | value |
|---|---|
| Original address | 0x005b5d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5d20 |
| Resolved name | roster_slot_remove_compact |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c08a0, FUN_005c0920, FUN_0062fd30
**Referenced globals:** 0x6c7c2c/3c/50 (roster table); 0x6c7d20 (slot id); 0x6c873c/4c/60 (tail slot); cRam006c550e (gate); 0x6c517c (dialog buf); 0x638e60 (title string ptr); cRam00343571 (variant)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c550e; uRam006c4fed

## Behavioral explanation
In room modes 4/0x0e: find local member in 4-slot roster (name-compare vs FUN_005c0920), zero its entry, compact remaining slots down, clear tail slot; on removal (mode!=send) reset dialog buffer 0x6c517c (0x300) and reload title string via FUN_0062fd30(0x89).

## Notes / uncertainty
Remove self from 4-slot roster by name-compare + compact + clear tail (screens 4/0x0e). Gate-off+removed -> leave dialog (localized string 0x89); mode 0x0e+gate -> FUN_005c08a0(0x10000/0x20000 by variant 0x343571). Transition target inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
