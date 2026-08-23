# 0x005d8a70 ui_set_color

| field | value |
|---|---|
| Original address | 0x005d8a70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8a70 |
| Resolved name | ui_set_color |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ef3f0
**Callees:** —
**Referenced globals:** 0x00701070 UI widget base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets the overlay widget color field (iRam00701070+0x14) to param|0xff000000, or forces opaque black when the widget's disabled flag +0x34 is set.

## Notes / uncertainty
Widget color +0x14 = rgb|0xff000000, forced opaque-black when disabled flag +0x34 set (greyed items). ARGB channel order and +0x34 label inferred from alpha-OR idiom/behavior. Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8a70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
