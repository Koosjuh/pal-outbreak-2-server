# 0x001ce5b0 group_slot_find_empty

| field | value |
|---|---|
| Original address | 0x001ce5b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce5b0 |
| Resolved name | group_slot_find_empty |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce740
**Callees:** —
**Referenced globals:** 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns a pointer to the first empty (byte0==0) slot in the 4-entry group table 0x36c310, or 0 if full.

## Notes / uncertainty
First-fit: returns first slot with active==0 in 0x36c310, else NULL (capacity 4). Trivial, unambiguous.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce5b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
