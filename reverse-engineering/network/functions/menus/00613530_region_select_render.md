# 0x00613530 region_select_render

| field | value |
|---|---|
| Original address | 0x00613530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613530 |
| Resolved name | region_select_render |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_006146e0, FUN_00614720
**Referenced globals:** 0x653f14 (region label ptr table); ctx+0x25 (availability bitmask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x25 region-avail bits

## Behavioral explanation
Renders the 2-item region/page selector: for each of 2 entries colors bright/dim by availability bit in ctx+0x25 and draws the label from PTR table 0x653f14.

## Notes / uncertainty
2-item region selector; per-entry avail bit in ui_ctx+0x25 picks bright/dim color, label from PTR table 0x653f14. Coords 0xdb/0xc4 pixel-vs-slot unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
