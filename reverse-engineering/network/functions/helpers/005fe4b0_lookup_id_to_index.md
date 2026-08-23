# 0x005fe4b0 lookup_id_to_index

| field | value |
|---|---|
| Original address | 0x005fe4b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe4b0 |
| Resolved name | lookup_id_to_index |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fcc70, FUN_005fd9e0, FUN_00601d50, FUN_00602340, FUN_00605790, FUN_00617c30, FUN_0062f5b0
**Callees:** —
**Referenced globals:** 0x3c4d50 id table (999-terminated)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Table lookup (@0x3c4d50 stride 0xc): returns the row index for (param-1), or -1 if the 999-terminated table has no match.

## Notes / uncertainty
Leaf: maps 1-based id to row index in table 0x3c4d50 (stride 0xc, u16 key), 999 sentinel -> -1. Trivially correct by inspection; 7 callers. Row layout beyond key field not mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe4b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
