# 0x001d8d70 bswap_inbound_list_fixed24_c

| field | value |
|---|---|
| Original address | 0x001d8d70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8d70 |
| Resolved name | bswap_inbound_list_fixed24_c |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d7b30, FUN_001d8710
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a fixed-0x24-stride record array: header swap then bswap_hdr_5w_10 per entry.

## Notes / uncertainty
Inbound op0x0b (case 8, conn+0x5b4). Fixed 0x24, contiguous 5-word swap +0x10..+0x20 (FUN_001d7b30, also used inline for op0x04). Opcode semantics unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8d70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
