# 0x005b6570 roster_and_scoreblock_remove_compact

| field | value |
|---|---|
| Original address | 0x005b6570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6570 |
| Resolved name | roster_and_scoreblock_remove_compact |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0920
**Referenced globals:** 0x6c7c2c/3c/50 (roster table, stride 0x3b0); 0x6c873c/4c/60 (tail slot); iRam003435d4+0xc942c (0x830-stride player-data array)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90

## Behavioral explanation
In mode 0x0c (leave/exit-room): find local member in 4-slot roster, remove+compact it, then similarly remove+compact the matching 0x830-stride per-player block in the array at iRam003435d4+0xc942c.

## Notes / uncertainty
Exit-room (screen 0x0c) variant: remove self from roster (saving tag block as key) then remove+compact matching 0x830-stride per-player score/state block at iRam003435d4+0xc942c. Relevant to exit-room stall. 0x830 block contents beyond match key (+4) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
