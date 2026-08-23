# 0x005d6a70 pool_find_move_to_front

| field | value |
|---|---|
| Original address | 0x005d6a70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6a70 |
| Resolved name | pool_find_move_to_front |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7760, FUN_005d78d0
**Callees:** FUN_005dedb0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x104 in-use flag

## Behavioral explanation
Searches a pool's active nodes ([0x41]!=0) for a key match via FUN_005dedb0 and moves the hit to the list front (move-to-front lookup).

## Notes / uncertainty
MRU associative lookup: compares 0x100-byte key of in-use nodes via FUN_005dedb0 (0=match, memcmp-style assumed), moves hit to front. Comma-expr bookkeeping preserved from decompile.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6a70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
