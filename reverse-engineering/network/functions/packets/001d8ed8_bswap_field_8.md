# 0x001d8ed8 bswap_field_8

| field | value |
|---|---|
| Original address | 0x001d8ed8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8ed8 |
| Resolved name | bswap_field_8 |
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
Byte-swaps the single 32-bit field at +8 of a message.

## Notes / uncertainty
Leaf: swap u32 @+0x08. Used inline in op0x28 selector sub-0x06 path (conn+0x5d0, called with payload+1). Field meaning undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8ed8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
