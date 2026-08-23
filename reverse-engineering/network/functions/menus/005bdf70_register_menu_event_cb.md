# 0x005bdf70 register_menu_event_cb

| field | value |
|---|---|
| Original address | 0x005bdf70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdf70 |
| Resolved name | register_menu_event_cb |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b25c0
**Callees:** —
**Referenced globals:** 0x6ca8a0 menu-event callback table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stores a callback pointer into the menu-event dispatch table at 0x6ca8a0 indexed by event id.

## Notes / uncertainty
table[id]=cb into menu-event callback table 0x6ca8a0, no bounds check; register counterpart of dispatch_menu_event.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdf70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
