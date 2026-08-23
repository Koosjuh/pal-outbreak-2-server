# 0x001d26f0 load_zone_layout_table

| field | value |
|---|---|
| Original address | 0x001d26f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d26f0 |
| Resolved name | load_zone_layout_table |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ccd50
**Callees:** FUN_001889b0, FUN_00188ab0, FUN_00189bb0, FUN_00199850, FUN_00199890, FUN_001998c0, FUN_001a9a90, FUN_001a9ae0
**Referenced globals:** 0x3f41a0 / 0x3435bc+0x2ff000 dest; struct+0x820 count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads grouped scene records and builds per-group index/count layout tables (dest chosen by param_3).

## Notes / uncertainty
Builds per-group index/count layout (no geometry copy); dest 0x3f41a0 or scratch by param_3; header +0x824, count +0xc24, id-list +0x1024. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d26f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
