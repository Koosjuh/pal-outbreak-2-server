# 0x001d7ab0 bswap_field_10

| field | value |
|---|---|
| Original address | 0x001d7ab0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d7ab0 |
| Resolved name | bswap_field_10 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps the single 32-bit field at +0x10 of a message header (endian normalize).

## Notes / uncertainty
bswap32 of 1 word at +0x10. Dispatched by opcode from FUN_001d9f78. Mechanics certain; opcode mapping unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d7ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
