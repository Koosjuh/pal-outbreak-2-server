# 0x001d7b30 bswap_hdr_5w_10

| field | value |
|---|---|
| Original address | 0x001d7b30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d7b30 |
| Resolved name | bswap_hdr_5w_10 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d8d70, FUN_001d9f78
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps five consecutive 32-bit fields (+0x10..+0x20) of a record.

## Notes / uncertainty
Swaps 5 words +0x10..+0x20 (0x24 fixed record). Per-entry for 0x24-stride parser FUN_001d8d70 + dispatch. Opcode unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d7b30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
