# 0x006049b0 roster_insert_or_find

| field | value |
|---|---|
| Original address | 0x006049b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006049b0 |
| Resolved name | roster_insert_or_find |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180, FUN_006195b0, FUN_006296a0
**Callees:** FUN_00604860, FUN_006048f0
**Referenced globals:** 0x694700 (member pool, via callers)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Upsert into a 0x38-stride member pool: if id already present return existing (0), else claim first free slot, copy record+id, zero counter at +0x20, return 1; -1 if full.

## Notes / uncertainty
Pool upsert (0x38 stride, cap 0x32): returns 0=found / 1=inserted / -1=full; writes record@+0, id@+0x10, zeroes ctr@+0x20. FUN_00604860 id arg dropped from this call's decompiled signature (inferred from caller passing (pool,0x32,id)); algorithm unaffected.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006049b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
