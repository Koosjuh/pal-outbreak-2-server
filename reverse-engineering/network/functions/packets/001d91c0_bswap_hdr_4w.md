# 0x001d91c0 bswap_hdr_4w

| field | value |
|---|---|
| Original address | 0x001d91c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d91c0 |
| Resolved name | bswap_hdr_4w |
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
Byte-swaps the first four 32-bit words of a buffer.

## Notes / uncertainty
Leaf: swap first 4 u32 (fixed 16-byte header). Shared by op0x6e (case 0x6b, conn+0x5f4) and op0x78 (case 0x75, conn+0x5f8). Header field meaning unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d91c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
