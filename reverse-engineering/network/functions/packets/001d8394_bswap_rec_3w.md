# 0x001d8394 bswap_rec_3w

| field | value |
|---|---|
| Original address | 0x001d8394 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8394 |
| Resolved name | bswap_rec_3w |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d8ab0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps three fields (+0x10,+0x14,+0x18) of a 0x1c record.

## Notes / uncertainty
Swaps 3 words +0x10..+0x18 (0x1c record). Per-entry for 0x1c-stride parser FUN_001d8ab0. Opcode unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8394.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
