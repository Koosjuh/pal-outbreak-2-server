# 0x001d8f58 bswap_rec_4w_10

| field | value |
|---|---|
| Original address | 0x001d8f58 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8f58 |
| Resolved name | bswap_rec_4w_10 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d90ec
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps four fields (+0x10,+0x14,+0x18,+0x1c) of a record.

## Notes / uncertainty
Leaf per-entry swapper for op0x25 list (caller FUN_001d90ec). Swaps +0x10/+0x14/+0x18/+0x1c; +0x1c is the record length consumed by caller stride.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8f58.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
