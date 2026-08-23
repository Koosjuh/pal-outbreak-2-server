# 0x00601580 build_roster_display_blocks4

| field | value |
|---|---|
| Original address | 0x00601580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601580 |
| Resolved name | build_roster_display_blocks4 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c2740
**Referenced globals:** iRam003435d4+0xc942c display blocks; 0x6c7c2c/3c/50 member fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate

## Behavioral explanation
Render/refresh callback: rebuilds the 4 room-member display blocks in the 0x830-stride table at 0xc942c from the decoded 0x6c7c2c/3c fields, marking occupied slots ([0]=1,[1]=1).

## Notes / uncertainty
Render-path variant: decodes roster (FUN_005c2740, stride 0x3b0) AND rebuilds 4 display blocks at 0xc942c stride 0x830, marking occupied ([0]=[1]=1) when name non-empty. Difference vs FUN_005c0d30 (data-only decoder) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
