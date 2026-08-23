# 0x005df700 str_prefix_match_table

| field | value |
|---|---|
| Original address | 0x005df700 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df700 |
| Resolved name | str_prefix_match_table |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df780
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Compares a string against a NULL-terminated array of prefix strings, returning the matching index or -1.

## Notes / uncertainty
Generic NULL-term prefix-table matcher: strncmp(subject,entry,strlen(entry)); returns first match index or -1. strlen/strncmp inferred. Reusable core wrapped by url_scheme_class.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df700.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
