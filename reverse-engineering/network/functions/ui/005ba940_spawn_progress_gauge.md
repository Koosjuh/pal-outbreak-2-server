# 0x005ba940 spawn_progress_gauge

| field | value |
|---|---|
| Original address | 0x005ba940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba940 |
| Resolved name | spawn_progress_gauge |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc0c0
**Callees:** FUN_00618ba0
**Referenced globals:** 0x639e28 gauge sprite table; 0x006c552c fRam=gauge phase; 0x006c5528 fRam=fill rate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** fRam006c552c; fRam006c5528

## Behavioral explanation
Spawns two gauge display nodes (callback FUN_005baa70, sprites from 0x639e28) and initializes the fill rate fRam006c5528 = 100/param and phase uRam006c552c=0.

## Notes / uncertainty
Spawns 2 gauge sprite nodes (bg idx0, fill idx1) cb=005baa70, sets phase 0x6c552c=0 and rate 0x6c5528=100/steps. Aborts if table full leaving globals unset. +0x34=-24 meaning open; no divide-by-zero guard.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
