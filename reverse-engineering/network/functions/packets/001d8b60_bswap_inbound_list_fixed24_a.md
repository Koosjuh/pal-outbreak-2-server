# 0x001d8b60 bswap_inbound_list_fixed24_a

| field | value |
|---|---|
| Original address | 0x001d8b60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8b60 |
| Resolved name | bswap_inbound_list_fixed24_a |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d81a4, FUN_001d8710
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a fixed-0x24-stride record array: header swap then bswap_rec_5w per entry.

## Notes / uncertainty
Inbound op0x47 (case 0x44, conn+0x608). Fixed 0x24 stride, per-entry FUN_001d81a4 (5 u32). Body-identical to 0x001d8c10 (op0x48); demux binds distinct callbacks.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
