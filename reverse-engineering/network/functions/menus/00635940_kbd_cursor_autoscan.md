# 0x00635940 kbd_cursor_autoscan

| field | value |
|---|---|
| Original address | 0x00635940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635940 |
| Resolved name | kbd_cursor_autoscan |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** FUN_00631670, FUN_00635ab0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x2f mode; 0x20 disabled-key bitmask; 0x4a bit0; 0x48 blink-counter; 0x24/0x25 cursor; 0x26 confirm; 0x248 status

## Behavioral explanation
Cursor blink/auto-advance timer: increments counter 0x48, derives grid col/row 0x24/0x25 from it (mod/div 0x14), clamps, and repaints via FUN_00635ab0.

## Notes / uncertainty
RENAMED from blink_autorepeat: hold-to-sweep cursor auto-scan (+0x48 counter +=5 wrap 0x3B, derives col%0x14/row/0x14, clamp 5,0), gated by mode/restrict-bit 0x20/layout+0x28. Scan/repaint helpers not reconstructed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
