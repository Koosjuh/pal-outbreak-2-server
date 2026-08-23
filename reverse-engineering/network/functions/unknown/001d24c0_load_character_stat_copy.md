# 0x001d24c0 load_character_stat_copy

| field | value |
|---|---|
| Original address | 0x001d24c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d24c0 |
| Resolved name | load_character_stat_copy |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cfb30
**Callees:** FUN_001a9d30
**Referenced globals:** 0x4172c0 count; 0x417384/0x417504 index tables; 0x52d620 stat table; 0x4052a8/0x404aa8 LUTs
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads a packed table into 0x417384 index arrays and copies 0x4c-byte stat blocks from the 0x52d620 table.

## Notes / uncertainty
Clones 0x4c-byte template stat blocks from 0x52d620 via 0x4052a8->0x404aa8 LUT chain, overlays payload transform; index arrays 0x417384/0x417504. Decompiler reuses lVar12 across both loops (preserved verbatim). Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d24c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
