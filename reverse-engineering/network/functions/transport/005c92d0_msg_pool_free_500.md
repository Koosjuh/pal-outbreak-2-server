# 0x005c92d0 msg_pool_free_500

| field | value |
|---|---|
| Original address | 0x005c92d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c92d0 |
| Resolved name | msg_pool_free_500 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8ed0
**Callees:** FUN_005dfee0
**Referenced globals:** 0x701068+0x5ffc0 (pool ptr array)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Frees the 500-slot message-buffer pool (FUN_005dfee0) and nulls each pool slot.

## Notes / uncertainty
Mirror teardown of the 500-slot pool: free (FUN_005dfee0) + null each slot until first null terminator. Free-fn takes no visible slot arg (internal allocator state).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c92d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
