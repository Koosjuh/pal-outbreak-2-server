# 0x001d8848 bswap_varlist_len14

| field | value |
|---|---|
| Original address | 0x001d8848 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8848 |
| Resolved name | bswap_varlist_len14 |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d80c8, FUN_001d8710
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a variable-length record list: swaps the header then each entry via bswap_2w_10_14, advancing by (entry+0x14 len) with a 0x37d count guard.

## Notes / uncertainty
Variable-stride inbound list normalizer: header swap + loop (count<0x37d guard) swapping entry +0x10/+0x14, stride=(len+0x1b)&~3 = align4(0x18+len). Length swapped before stride read (correct). Parse mechanics High; owning opcode unresolved (0x18-head+var-body suggests text/name list). Raised from Medium given clear reconstruction.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8848.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
