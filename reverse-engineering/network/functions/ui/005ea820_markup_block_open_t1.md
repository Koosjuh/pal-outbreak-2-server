# 0x005ea820 markup_block_open_t1

| field | value |
|---|---|
| Original address | 0x005ea820 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea820 |
| Resolved name | markup_block_open_t1 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef0e0, FUN_005ef550, FUN_005ef850, FUN_005f0e10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Block-element (type 1) open: FUN_005f0e10 begins the element, then runs layout (FUN_005ef0e0/005ef550) and commit (FUN_005ef850(1)); returns -1 on failure.

## Notes / uncertainty
Block-element kind-1 open: begin (FUN_005f0e10,sel=1) -> apply attrs -> layout step -> commit (FUN_005ef850,1); returns -1 on begin/commit failure. No finalize (sibling 0x5ea880 adds it). param roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea820.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
