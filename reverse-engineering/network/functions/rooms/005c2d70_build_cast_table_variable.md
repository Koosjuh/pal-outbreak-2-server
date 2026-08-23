# 0x005c2d70 build_cast_table_variable

| field | value |
|---|---|
| Original address | 0x005c2d70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2d70 |
| Resolved name | build_cast_table_variable |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2f40
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates param_3 4-byte descriptors and appends one cast-display block per active descriptor into the 0x14a5-stride buffer; returns the number of blocks written.

## Notes / uncertainty
Appends one cast block per active 4-byte descriptor over param_3 descriptors; per-block count read from source rec+0x1f. Sibling of 005c2bc0; caller FUN_005c2f40 runs it twice (desc lists at +3 and +0x2c) after the fixed pass. Copy size / +0x44 field uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2d70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
