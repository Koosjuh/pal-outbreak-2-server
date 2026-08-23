# 0x00604a80 roster_member_bump_refcount

| field | value |
|---|---|
| Original address | 0x00604a80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604a80 |
| Resolved name | roster_member_bump_refcount |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180, FUN_006195b0
**Callees:** FUN_00604860
**Referenced globals:** member pool +0x20 (refcount)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Finds a member by id in a pool and increments its refcount at +0x20 (saturating at -1); returns 1 on hit, -1 if absent.

## Notes / uncertainty
table_find_by_id(pool,0x32,id) then increment refcount +0x20 (saturate at -1 sentinel). -1 sentinel = pin, inferred; paired decrement not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604a80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
