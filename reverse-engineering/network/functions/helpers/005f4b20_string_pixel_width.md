# 0x005f4b20 string_pixel_width

| field | value |
|---|---|
| Original address | 0x005f4b20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4b20 |
| Resolved name | string_pixel_width |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4be0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sums the pixel advance of every glyph in a variable-width-font string.

## Notes / uncertainty
Sums VWF glyph advance over a (multi-byte) string via 001af430. Decompile conflates pixel-advance with byte-step (same iVar1); needs runtime read to separate. Used by softkbd commit. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4b20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
