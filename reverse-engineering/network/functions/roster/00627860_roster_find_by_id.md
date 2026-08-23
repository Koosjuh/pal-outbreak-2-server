# 0x00627860 roster_find_by_id

| field | value |
|---|---|
| Original address | 0x00627860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627860 |
| Resolved name | roster_find_by_id |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006278e0
**Callees:** —
**Referenced globals:** 0x715500 roster-disp-table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Linear-searches the 0x715500 display table (50 slots, 0x14 stride) for an entry whose 16-byte id matches param; returns index or -1.

## Notes / uncertainty
Linear memcmp(16) search of the 0x715500 display table (occupancy = id[0]!=0), returns index or -1. Fully determined by decompile.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
