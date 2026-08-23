# 0x005b8130 alloc_menu_widget_obj

| field | value |
|---|---|
| Original address | 0x005b8130 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8130 |
| Resolved name | alloc_menu_widget_obj |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b4c80, FUN_005b7fd0, FUN_005fc850, FUN_00617bb0
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocate a menu widget object (FUN_00618ba0) and initialize it from a 6-short descriptor (type@+0x22, callback@+0xc, subtype@+3).

## Notes / uncertainty
Pool-allocs widget, seeds active/substate=1, type(+0x22), handler(+0xc), subtype(+3) from descriptor. +0xc handler vs +0x10 action treated as distinct slots.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
