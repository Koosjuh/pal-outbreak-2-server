# 0x005ba520 draw_displaylist_entry

| field | value |
|---|---|
| Original address | 0x005ba520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba520 |
| Resolved name | draw_displaylist_entry |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628860
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a single display descriptor: set palette(+2)/mode(+1) then FUN_005af1e0(+4,+6,+3,param_2 string).

## Notes / uncertainty
Single text-entry draw from a byte-packed DrawEntry descriptor (+1 size,+2 color,+3 mode,+4/+6 x/y) via ui_draw_set_color/size/text. 'mode' byte semantics unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
