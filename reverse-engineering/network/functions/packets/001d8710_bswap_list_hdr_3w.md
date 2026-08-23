# 0x001d8710 bswap_list_hdr_3w

| field | value |
|---|---|
| Original address | 0x001d8710 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8710 |
| Resolved name | bswap_list_hdr_3w |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d8848, FUN_001d89f8, FUN_001d8ab0, FUN_001d8b60, FUN_001d8c10, FUN_001d8cc0, FUN_001d8d70, FUN_001d90ec
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps a 3-word list header (count/type/len) preceding a variable record array.

## Notes / uncertainty
Swaps the 3-word list header (words 0/1/2); +0x08 = entry count consumed by all 8 list parsers. Meaning of header words 0,1 (type/len?) not pinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
