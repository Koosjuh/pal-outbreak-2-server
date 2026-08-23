# 0x005e2fa0 draw_element_main

| field | value |
|---|---|
| Original address | 0x005e2fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e2fa0 |
| Resolved name | draw_element_main |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daf30
**Callees:** FUN_001ae3e0, FUN_005ddc20, FUN_005dfbc0, FUN_005e0440, FUN_005e0570, FUN_005e07c0, FUN_005e15e0, FUN_005e19b0, FUN_005e1a30, FUN_005e1da0
**Referenced globals:** iRam00701070+4/+8 (scroll), +0x18 flags; iRam00701068+0x69018 (blink/anim timer), +0x68dd8 (glyph sheets)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x69018; iRam00701070+0x18

## Behavioral explanation
Main per-element draw dispatcher: viewport-culls an element then switch(type 1..0x12) renders text (FUN_005ddc20), frames/buttons (FUN_005e07c0), checkboxes, lines and glyph runs; sets element+1 'visible' flag.

## Notes / uncertainty
Main per-element dispatcher: switch(type 1..0x12) text/fields/checkboxes/marquee/lines; case 0x0d = roster/name glyph cell via +0x68dd8/+0x68e28/+0x68e50. Sets visible flag elem[1]. Field aliases str/str2/hasLabel inferred; marquee cadence unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e2fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
