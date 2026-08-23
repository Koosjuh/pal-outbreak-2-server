# 0x005d6ce0 roster_pool_free_node

| field | value |
|---|---|
| Original address | 0x005d6ce0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6ce0 |
| Resolved name | roster_pool_free_node |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d78d0, FUN_005d79e0, FUN_005d7a30, FUN_005d8340
**Callees:** FUN_005d6b80
**Referenced globals:** 0x004f47c (base+off: roster pool head)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x114 handle; node+0x10c/0x110/0x118/0x11a

## Behavioral explanation
Returns a node to the roster/user pool (head base+0x4f47c), runs its destructor func_0x001cb490 if +0x114 set, clears +0x10c/0x110/0x118/0x11a.

## Notes / uncertainty
Frees one 0x114 roster node: unlink, run resource destructor if +0x114 handle set, zero link/aux fields. Destructor func_0x001cb490 identity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6ce0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
