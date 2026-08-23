# 0x005c27d0 menu_build_entry_0xda_ret

| field | value |
|---|---|
| Original address | 0x005c27d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c27d0 |
| Resolved name | menu_build_entry_0xda_ret |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2390, FUN_005c2460
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 (UI/handler object block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers/initializes a UI handler object (id 0xda) at 0x7018d0 via the be9e0/bea10/bea80 register triad; returns the id.

## Notes / uncertainty
No-label terminal menu-entry builder (id 0xda) used by dialog builders 0x5c2390/0x5c2460; returns handle. Same stub-callee caveat; original alias register_ui_obj_0xda retained. UI-only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c27d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
