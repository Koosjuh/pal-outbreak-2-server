# 0x005da650 ui_track_max_extent

| field | value |
|---|---|
| Original address | 0x005da650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da650 |
| Resolved name | ui_track_max_extent |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8b90, FUN_005d8c90, FUN_005d8d60, FUN_005d8e00, FUN_005d8ea0, FUN_005d8f90, FUN_005d9030, FUN_005d9160, FUN_005d9350, FUN_005d9450, FUN_005d9520, FUN_005d96a0, FUN_005d9790, FUN_005d9940, FUN_005d9ac0, FUN_005d9bd0, FUN_005d9ca0, FUN_005da420
**Callees:** —
**Referenced globals:** iRam00701070+0x10: max height; iRam00701070+0xc: max width; iRam00701070+0x22/0x26: scale ratios; iRam00701070+0x2a/0x2b: overflow flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0xc; 0x10; 0x2a; 0x2b

## Behavioral explanation
UI viewport bounds tracker (18 callers): raises stored max height (+0x10) and width (+0xc), recomputes scale ratios (0x20490/h, 0x4eb40/w) and sets overflow flags when h>0x17c / w>0x248.

## Notes / uncertainty
18-caller bounds accumulator: raises max w/h, recomputes thumb ratios (0x20490/h, 0x4eb40/w), sets overflow flags at 380/584px. Numerator provenance inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
