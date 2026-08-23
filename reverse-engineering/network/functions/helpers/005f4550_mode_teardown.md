# 0x005f4550 mode_teardown

| field | value |
|---|---|
| Original address | 0x005f4550 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4550 |
| Resolved name | mode_teardown |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6b00, FUN_005f6d20, FUN_00606cb0
**Callees:** FUN_005f4440
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Tears down the current mode: frees asset handles and resets render/input state.

## Notes / uncertainty
Mode-exit: subsystem deinit + free_resource_handles + render/scene/DMA resets. Mirror of mode_config_init. func_0x thunk names inferred. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
