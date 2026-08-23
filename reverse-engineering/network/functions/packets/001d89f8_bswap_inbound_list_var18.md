# 0x001d89f8 bswap_inbound_list_var18

| field | value |
|---|---|
| Original address | 0x001d89f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d89f8 |
| Resolved name | bswap_inbound_list_var18 |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d8710, FUN_001d891c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a variable-stride record list: header swap then each entry via bswap_2w_10_18, advancing by (entry+0x18 len).

## Notes / uncertainty
Inbound normalizer op0x43 (demux case 0x40, handler conn+0x600, who!=DATA). Variable stride round_up(0x1c+len@+0x18,4); NO 0x37d count cap (unlike siblings). Opcode-to-named-message unmapped.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d89f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
