# 0x005e2060 draw_screen_frame_and_header

| field | value |
|---|---|
| Original address | 0x005e2060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e2060 |
| Resolved name | draw_screen_frame_and_header |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd3e0, FUN_005dc010, FUN_005e4840
**Callees:** FUN_005ddb40, FUN_005ddc20, FUN_005de330, FUN_005e00e0, FUN_005e0440, FUN_005e2030
**Referenced globals:** iRam00701070+0x5c3 (screen mode), +0x18 flags, +0x34/+0x36 state, +0x3a fade; iRam00701068+0x5ffc0 (element list), +0x68e83..85 (menu state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701070+0x5c3; iRam00701070+0x18; iRam00701068+0x68e83/84/85

## Behavioral explanation
Renders the screen letterbox borders and a mode-dependent header (title icon/text) keyed off viewport state +0x5c3, plus a fade-in/out alpha ramp on +0x3a.

## Notes / uncertainty
Screen chrome: letterbox bars, header banner (switch on +0x5c3 -> string group 9), comms icons (flag 0x100), modal-dim gate on menu-state (0,2,1), fade ramp on +0x3a. Field names borderFull/sideBarsOff inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e2060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
