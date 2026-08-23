# 0x0062f710 room_ui_blink_task

| field | value |
|---|---|
| Original address | 0x0062f710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f710 |
| Resolved name | room_ui_blink_task |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20
**Referenced globals:** 0x694630 sin-scale const
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI task update: animates a blinking element — advances phase +0x3a by 0x400, computes alpha via sin (func_0x001886c0 * DAT_00694630) into color +0x2c; sizes box by +2 flag.

## Notes / uncertainty
Blink widget callback: lazy first-frame init (width 0x100/0x168 by index) then sin-modulated alpha into +0x2c each frame; +9 restart snaps phase to peak. Widget role (cursor/highlight/frame) Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
