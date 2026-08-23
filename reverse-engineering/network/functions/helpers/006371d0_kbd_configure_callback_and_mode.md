# 0x006371d0 kbd_configure_callback_and_mode

| field | value |
|---|---|
| Original address | 0x006371d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006371d0 |
| Resolved name | kbd_configure_callback_and_mode |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b45f0, FUN_005dc1e0, FUN_005dc2b0, FUN_005f4be0, FUN_005f97c0, FUN_005faa60, FUN_006149f0, FUN_00625190, FUN_0062adb0, FUN_0062d3d0
**Callees:** —
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x40 param; 0x38 param

## Behavioral explanation
Setter: stores param_1→struct+0x40 and param_2→struct+0x38 (widget config, e.g. buffer/limit or field id) at open time.

## Notes / uncertainty
Two-field setter: +0x40=u32 cfg (likely context/callback ptr, [inferred]), +0x38=u16 mode. Consumer of these fields not traced, so field meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006371d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
