# 0x005c78e0 async_op_state_reset

| field | value |
|---|---|
| Original address | 0x005c78e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c78e0 |
| Resolved name | async_op_state_reset |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0
**Callees:** —
**Referenced globals:** 0x700fd8/0x700fd0/0x700fc8 (async stage flags)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fd8

## Behavioral explanation
Resets the three-stage async-operation state cells (0x700fd8/fd0/fc8) to 0.

## Notes / uncertainty
Zeroes 3 async-stage flags 0x700fd8/fd0/fc8 for the room-list ladder. Per-stage op identity not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c78e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
