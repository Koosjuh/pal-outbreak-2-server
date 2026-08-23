# 0x001d8cc0 bswap_inbound_roomlist_op49

| field | value |
|---|---|
| Original address | 0x001d8cc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8cc0 |
| Resolved name | bswap_inbound_roomlist_op49 |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d7d20, FUN_001d8710
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a fixed-0x28-stride record array: header swap then bswap_hdr_6w_10 per entry.

## Notes / uncertainty
Inbound op0x49 room-list (case 0x46, conn+0x610). Fixed 0x28 stride = room_record op49; swaps 6 u32 +0x10..+0x24. Note: swaps +0x10 (name doc says char[20]) and +0x24 handle (doc says LE) — reconcile vs live op49.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8cc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
