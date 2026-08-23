# 0x001d861c bswap_name_record_at8

| field | value |
|---|---|
| Original address | 0x001d861c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d861c |
| Resolved name | bswap_name_record_at8 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** —
**Referenced globals:** —
**Referenced strings:** NAME (0x4e414d45)
**Referenced opcodes:** 0x48
**State vars:** —

## Behavioral explanation
Byte-swaps the field at +8 and, unless it is the 'NAME' tag, the field at +0xc — name-record normalizer at a +8 base.

## Notes / uncertainty
Same NAME-guard normalizer at record base +8 (tag) / +0xc (value). Which layout puts tag at +8 not traced from caller FUN_001d9f78.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d861c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
