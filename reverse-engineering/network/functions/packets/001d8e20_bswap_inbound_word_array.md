# 0x001d8e20 bswap_inbound_word_array

| field | value |
|---|---|
| Original address | 0x001d8e20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8e20 |
| Resolved name | bswap_inbound_word_array |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d8048
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps a leading count word then that many following 32-bit words (count-guarded < 0xe0).

## Notes / uncertainty
Inbound op0x10 room-info (case 0xd, flag-selected conn+0x59c/594/578/580). Flat count-prefixed u32 array (count@+0, cap<0xe0) — different header shape from list parsers. Data-word meaning undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8e20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
