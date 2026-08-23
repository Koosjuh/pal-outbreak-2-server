# 0x005e0570 draw_cursor_sprite

| field | value |
|---|---|
| Original address | 0x005e0570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0570 |
| Resolved name | draw_cursor_sprite |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dcb90, FUN_005e2fa0
**Callees:** FUN_005ddb40, FUN_005e00e0
**Referenced globals:** iRam00701068+0x607c0 (via FUN_005e00e0 sprite sheet 0)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blits a mouse/hand cursor or corner sprite: switch on glyph id (0x18-0x1b,0x00,0x01) selects atlas UV coords and calls FUN_005ddb40.

## Notes / uncertainty
Blits cursor/marker sprite from atlas sheet 0 by glyph id: 0x18-0x1b=20px markers (UV 0xe0/0xf0 x 0xc0/0xd0), 0x00/0x01=32px cursors (-3px bias). Which id = which on-screen graphic unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
