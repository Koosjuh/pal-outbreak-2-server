# 0x001e5934 byteswap_u32_array

| field | value |
|---|---|
| Original address | 0x001e5934 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e5934 |
| Resolved name | byteswap_u32_array |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e5a00, FUN_001ea804
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps each 32-bit word of a buffer in place (endian bswap) over param_2 bytes; SHA-1 message-schedule/endian helper.

## Notes / uncertainty
In-place bswap32 over len>>2 words; SHA-1 endian normalization helper. Trailing <4B ignored. Certain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e5934.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
