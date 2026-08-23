# 0x001d90ec bswap_inbound_list_var1c

| field | value |
|---|---|
| Original address | 0x001d90ec |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d90ec |
| Resolved name | bswap_inbound_list_var1c |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d8710, FUN_001d8f58
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a variable-stride record list: header swap then bswap_rec_4w_10 per entry, advancing by (entry+0x1c len).

## Notes / uncertainty
Inbound op0x25 (case 0x22, conn+0x5ec). Variable stride round_up(0x20+len@+0x1c,4), count<0x37d. Opcode semantics unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d90ec.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
