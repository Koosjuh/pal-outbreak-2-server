# 0x005bc990 name_query_reply_callback

| field | value |
|---|---|
| Original address | 0x005bc990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc990 |
| Resolved name | name_query_reply_callback |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdc70, FUN_005bdf90, FUN_005c5060, FUN_005c7e30, FUN_005c7f20
**Referenced globals:** 0x86f7f8 (accumulator); 0x86f800 (threshold input); 0x6fc5e8 (0x300 event buffer); 0x639e68 (error-string table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Callback for the NAME query (sub-type 0): sums a per-entry 16-bit field across the returned member list (count at resp+8, stride 0x24) and compares to a threshold (FUN_005c5060) to branch to FUN_005bdc70 vs error screen 8; sub-type '\'' shows an error dialog from table 0x639e68.

## Notes / uncertainty
op48 NAME reply cb: sums s16 entry+0x10 over stride-0x24 list vs threshold FUN_005c5060(0x86f800); proceed or 'full' screen 8; 0x27=error dialog. Summed-field semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc990.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
