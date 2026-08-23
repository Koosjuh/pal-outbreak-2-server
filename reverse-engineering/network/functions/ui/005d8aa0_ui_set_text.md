# 0x005d8aa0 ui_set_text

| field | value |
|---|---|
| Original address | 0x005d8aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8aa0 |
| Resolved name | ui_set_text |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8530
**Callees:** FUN_005dee00
**Referenced globals:** 0x00701070 UI widget base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a string into the overlay widget text buffer (iRam00701070+0x13b) and post-processes via FUN_005dee00 (layout/measure).

## Notes / uncertainty
Main text buffer +0x13b (memset 0x100 + strcpy) then FUN_005dee00 layout/measure. Exact role of FUN_005dee00 (measure vs wrap vs glyph-cache) not decompiled. Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8aa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
