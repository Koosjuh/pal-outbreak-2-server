# 0x00613fb0 menu_render_list_with_edit_row

| field | value |
|---|---|
| Original address | 0x00613fb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613fb0 |
| Resolved name | menu_render_list_with_edit_row |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00613c30
**Callees:** FUN_0060f830, FUN_0060f860, FUN_006146e0, FUN_006147a0, FUN_00618520
**Referenced globals:** iRam0070d1c0 (+0x4e, +0x10d8 edit buf); 0x653ff0; 0x654010
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x10d8 (edit buffer)

## Behavioral explanation
Renders menu table but for the row matching param_1 substitutes a live edit buffer (cursor length from 618520) — text-entry field render.

## Notes / uncertainty
List with one dynamic row (param_1): row.str used as sprintf FORMAT with edit len(0x618520 of ctx+0x10d8)+1. 0x618520 caret/length semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613fb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
