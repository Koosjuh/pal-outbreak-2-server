# 0x006366a0 kbd_render_cursor_highlight

| field | value |
|---|---|
| Original address | 0x006366a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006366a0 |
| Resolved name | kbd_render_cursor_highlight |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00636890
**Callees:** FUN_006381e0
**Referenced globals:** 0x715da8 state struct; 0x692400/0x692401 key-cell offset table; 0x690d70 glyph metrics
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1f key-type; 0x25 cursor-row; 0x26 confirm; 0x09 layout-col-count

## Behavioral explanation
Draws the selection/cursor highlight quad for the active key: keys off key-type 0x1f (4/5 special) and cursor 0x25, using DAT_00692400/01 offset table, via FUN_006381e0.

## Notes / uncertainty
Draws selection highlight quad unless cursor on neutral home cell (0x692400/01 table, key-type 4/5 special). Caller passes color|0xd0000000. piRam[9] dual col-count/col role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006366a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
