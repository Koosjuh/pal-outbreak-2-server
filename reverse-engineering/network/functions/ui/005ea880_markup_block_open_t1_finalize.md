# 0x005ea880 markup_block_open_t1_finalize

| field | value |
|---|---|
| Original address | 0x005ea880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea880 |
| Resolved name | markup_block_open_t1_finalize |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ea900, FUN_005ef0e0, FUN_005ef550, FUN_005ef850, FUN_005f0e10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Type-1 block open variant that, after successful layout+commit, calls FUN_005ea900 to finalize the element geometry.

## Notes / uncertainty
Same as 0x5ea820 plus FUN_005ea900 geometry-finalize on success. Returns 0xffffffff on failure. Which tags dispatch here vs plain-open unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
