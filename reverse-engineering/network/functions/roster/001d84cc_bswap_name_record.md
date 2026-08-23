# 0x001d84cc bswap_name_record

| field | value |
|---|---|
| Original address | 0x001d84cc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d84cc |
| Resolved name | bswap_name_record |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** —
**Referenced globals:** —
**Referenced strings:** NAME (0x4e414d45)
**Referenced opcodes:** 0x48
**State vars:** —

## Behavioral explanation
Byte-swaps a record's first two words and, unless word1 is the 'NAME' tag, its third word too — the name-query record normalizer.

## Notes / uncertainty
op0x48 name-record endian normalizer: bswap word0/word1, and word2 UNLESS word1=='NAME'(0x4e414d45) since that word is raw ASCII. word0 numeric semantics unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d84cc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
