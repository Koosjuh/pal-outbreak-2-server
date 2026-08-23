# 0x005c8db0 state_handler_forward_stored_advance

| field | value |
|---|---|
| Original address | 0x005c8db0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8db0 |
| Resolved name | state_handler_forward_stored_advance |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005de0f0, FUN_005de110
**Referenced globals:** 0x701068+0x68dd0 (stored value); 0x701070+2 (sub-state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+2

## Behavioral explanation
State handler: forwards the stored reply value (0x68dd0) via FUN_005de110 and advances sub-state.

## Notes / uncertainty
Pipeline fn-ptr-table state: kick 5de0f0, forward stored reply (0x701068+0x68dd0) via 5de110, advance step (0x701070+2). Callee semantics inferred; table index unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8db0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
