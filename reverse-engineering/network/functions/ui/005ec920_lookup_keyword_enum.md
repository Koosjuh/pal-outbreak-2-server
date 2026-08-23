# 0x005ec920 lookup_keyword_enum

| field | value |
|---|---|
| Original address | 0x005ec920 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec920 |
| Resolved name | lookup_keyword_enum |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e60c0, FUN_005e94c0, FUN_005ea190, FUN_005eb300, FUN_005eb350, FUN_005eb990, FUN_005eb9f0
**Callees:** —
**Referenced globals:** DAT_006493b0 (fold table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Folds a token via table 0x6493b0 then linear-searches a {string,len,value} keyword table (param_2/param_3), returning the matched enum byte (attribute keyword -> value).

## Notes / uncertainty
Case-folds token (DAT_006493b0) into 256B buf, linear-scans 8B {word,len,value} records, returns value or 0. memcmp/strlen inferred; fold buffer unbounded (tokens short). Record +6/+7 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
