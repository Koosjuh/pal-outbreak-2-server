# 0x001d8ab0 bswap_inbound_list_fixed1c

| field | value |
|---|---|
| Original address | 0x001d8ab0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d8ab0 |
| Resolved name | bswap_inbound_list_fixed1c |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d8394, FUN_001d8710
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a fixed-0x1c-stride record array: header swap then bswap_rec_3w per entry, count-guarded by 0x37d.

## Notes / uncertainty
Inbound op0x0e (case 0xb, conn+0x5b0). Fixed 0x1c stride, per-entry swap +0x10/+0x14/+0x18, count<0x37d cap. Opcode semantics unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d8ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
