# 0x005b8a10 widget_cb_icon_anim

| field | value |
|---|---|
| Original address | 0x005b8a10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8a10 |
| Resolved name | widget_cb_icon_anim |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20
**Referenced globals:** 0x006c4fd3 cRam=pause/mode gate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd3

## Behavioral explanation
Display-object update callback: runs the +4 lifecycle SM, sets flags/color 0xff804000 and an icon id chosen by the +2 type byte (0x16/0x17/0x0b/0x00/0x19), advances a 6-bit +0x40 animation counter.

## Notes / uncertainty
Cursor/icon sprite tick; color 0xff804000, 6-bit +0x40 scroll, 64x64 cell. Unrelated to net; +0x42/44/46 sub-rect inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
