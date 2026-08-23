# 0x001d7d20 bswap_hdr_6w_10

| field | value |
|---|---|
| Original address | 0x001d7d20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d7d20 |
| Resolved name | bswap_hdr_6w_10 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d8cc0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Byte-swaps six 32-bit fields (+0x10..+0x24) of a record.

## Notes / uncertainty
Swaps 6 words +0x10..+0x24 (0x28 fixed record). Per-entry for 0x28-stride parser FUN_001d8cc0; 0x28 stride matches op49 room_record so plausible room-list normalizer (unconfirmed).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d7d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
