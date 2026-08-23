# 0x001d9354 bswap_word0

| field | value |
|---|---|
| Original address | 0x001d9354 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d9354 |
| Resolved name | bswap_word0 |
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
Byte-swaps a single 32-bit word at the buffer start.

## Notes / uncertainty
Leaf: swap single u32 @+0. Inbound op0x35 scalar (case 0x32, conn+0x5fc). Scalar meaning undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d9354.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
