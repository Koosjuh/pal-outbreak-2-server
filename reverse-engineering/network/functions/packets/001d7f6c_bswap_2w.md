# 0x001d7f6c bswap_2w

| field | value |
|---|---|
| Original address | 0x001d7f6c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d7f6c |
| Resolved name | bswap_2w |
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
Byte-swaps the first two 32-bit words of a buffer.

## Notes / uncertainty
Swaps 2 words at buffer base (+0x00,+0x04), not past a header. Dispatch from FUN_001d9f78. Opcode unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d7f6c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
