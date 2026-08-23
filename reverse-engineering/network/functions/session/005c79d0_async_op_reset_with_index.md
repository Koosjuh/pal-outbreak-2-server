# 0x005c79d0 async_op_reset_with_index

| field | value |
|---|---|
| Original address | 0x005c79d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c79d0 |
| Resolved name | async_op_reset_with_index |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00606fc0, FUN_00607370
**Callees:** —
**Referenced globals:** 0x86f800 (selected index); 0x700fd8/fd0/fc8 (stage flags)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fd8

## Behavioral explanation
Stores a selection index (0x86f800) and resets the async-stage flags.

## Notes / uncertainty
Begin/reset half of an indexed async lookup; clears the same stage(0x700fd0)/result(0x700fc8) cells that async_stage_poll_b pumps. Index-is-a-room-index and aux-vs-result-cell roles inferred from callers; no runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c79d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
