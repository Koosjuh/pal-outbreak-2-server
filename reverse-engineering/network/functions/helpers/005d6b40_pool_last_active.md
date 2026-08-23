# 0x005d6b40 pool_last_active

| field | value |
|---|---|
| Original address | 0x005d6b40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6b40 |
| Resolved name | pool_last_active |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7760, FUN_005d78d0, FUN_005d79e0, FUN_005d7a30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x104 in-use flag

## Behavioral explanation
Walks a pool list (guarded by *(head+0x104)!=0) and returns the last node whose in-use flag [0x41] is set.

## Notes / uncertainty
Last in-use node; fast-out if front slot free. Relies on inferred invariant that in-use nodes cluster at head.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6b40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
