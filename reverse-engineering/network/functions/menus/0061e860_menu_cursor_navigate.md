# 0x0061e860 menu_cursor_navigate

| field | value |
|---|---|
| Original address | 0x0061e860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e860 |
| Resolved name | menu_cursor_navigate |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00623be0
**Callees:** FUN_0061e720, FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e810
**Referenced globals:** 0x715309 (cursor index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715309 (menu cursor idx)

## Behavioral explanation
Menu cursor-nav step: reads input mask (e750), advances cursor bRam00715309 via e810, checks edges (e7f0/e800), returns move direction (-1/0/1).

## Notes / uncertainty
2-option (Yes/No) selector driver; returns 0=navigating,+1=option0,-1=option1/cancel. extraout_a1 = pre-step index (cursor-unchanged test); e720 move-SE opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
