# 0x001d0b90 load_pc_motion_dual_grid_cond

| field | value |
|---|---|
| Original address | 0x001d0b90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0b90 |
| Resolved name | load_pc_motion_dual_grid_cond |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360, FUN_001d0a50
**Referenced globals:** uRam003435bc work base
**Referenced strings:** 0x24cd00 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If param_1!=0, builds tmpl 0x24cd00, sends (flags 0x20001) and decodes into dual grids via FUN_001d0a50.

## Notes / uncertainty
MISCLASSIFICATION CORRECTED: not a roster fetch. ELF string 0x24cd00 = 'data\rom\motion\player\pc_%03d.bin' — loads playable-character motion, decodes dual grid (mode=1) via FUN_001d0a50. Conditional sibling of FUN_001d0b00 (sp_%03d.bin, mode 0). Uncertainty: %03d id arg dropped by decompiler (varargs); runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0b90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
