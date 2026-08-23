# 0x005df780 url_scheme_class

| field | value |
|---|---|
| Original address | 0x005df780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df780 |
| Resolved name | url_scheme_class |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7760, FUN_005d7cf0, FUN_005def30, FUN_005df170, FUN_005df340
**Callees:** FUN_005df700
**Referenced globals:** 0x646570 (scheme table, e.g. http/https)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Classifies a URL's scheme via str_prefix_match_table against the table at 0x646570, returning class+1 (0/1/2) used to gate authority parsing.

## Notes / uncertainty
Wraps str_prefix_match_table over table@0x646570, returns 1-based class (idx+1; 0=unknown). Exact table string contents not enumerated (needs data read at 0x646570).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
