# 0x005ec6d0 parse_number_or_percent

| field | value |
|---|---|
| Original address | 0x005ec6d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec6d0 |
| Resolved name | parse_number_or_percent |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9bd0, FUN_005eaad0, FUN_005eba50
**Callees:** —
**Referenced globals:** —
**Referenced strings:** % (percent suffix, char 0x25)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a decimal number; if it ends with '%', computes a percentage of param_2 (or of default 0x248 when param_2==0) — used for width/size attributes.

## Notes / uncertainty
"N"->N, "N%"->N*basis/100 with basis default 0x248(584). Empty-token would 1-byte underflow but callers pass non-empty. strlen inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec6d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
