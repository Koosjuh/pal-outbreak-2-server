# 0x001d0e90 load_demo_bg_motion

| field | value |
|---|---|
| Original address | 0x001d0e90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0e90 |
| Resolved name | load_demo_bg_motion |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360, FUN_001d09e0
**Referenced globals:** 0x4fa740 roster grid; uRam003435bc work base
**Referenced strings:** 0x24ce20 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds tmpl 0x24ce20, sends via FUN_001cb360 and decodes a grid8 into 0x4fa740 via FUN_001d09e0.

## Notes / uncertainty
MISCLASSIFICATION CORRECTED. ELF 0x24ce20 = 'data\rom\motion\demo\r%03d\b%02d.bin'. Single demo 'b'-series motion load+decode into 0x4fa740 (gated len>0). Semantic role of b-series inferred from filename; runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
