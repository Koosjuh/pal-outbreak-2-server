# 0x005b16c0 input_held

| field | value |
|---|---|
| Original address | 0x005b16c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b16c0 |
| Resolved name | input_held |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b0cd0, FUN_005b0f00, FUN_005b1190
**Callees:** —
**Referenced globals:** 0x6c4610 uRam006c4610 capability/permission bitmask; 0x6c462a cRam006c462a menu-context char
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4610; 0x6c462a

## Behavioral explanation
Predicate: returns 1 if a menu option (given by a flag-bitmask arg) is available in the current menu context, keyed on capability bits and the context char.

## Notes / uncertainty
RENAMED from menu_item_available_for_context: structural twin of input_pressed but tests held mask g_padHeld(0x6c4610); the 'context char' interpretation was a misclassification. Held vs held-or-repeat inferred from cursor_nav repeat idiom.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b16c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
