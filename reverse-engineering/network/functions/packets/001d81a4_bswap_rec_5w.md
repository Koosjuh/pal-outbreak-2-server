# 0x001d81a4 bswap_rec_5w

| field | value |
|---|---|
| Original address | 0x001d81a4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d81a4 |
| Resolved name | bswap_rec_5w |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d8b60, FUN_001d8c10
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps five fields (+0x10,+0x14,+0x18,+0x1c,+0x20) of a fixed 0x24 record.

## Notes / uncertainty
Swaps 5 words {+0x10,+0x14,+0x18,+0x1c,+0x20} (source order cosmetic). Same field-set as bswap_hdr_5w_10 but distinct fn for 0x24-stride parsers FUN_001d8b60/FUN_001d8c10. Reason for two variants unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d81a4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
