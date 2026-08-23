# 0x00619e00 hud_status_icon_render

| field | value |
|---|---|
| Original address | 0x00619e00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619e00 |
| Resolved name | hud_status_icon_render |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_00619d90, FUN_0061c7f0, FUN_0061c970, FUN_0061f4b0, FUN_0061f760
**Referenced globals:** cRam00715317 current-screen id; sRam007152e8/ea menu cursor; cRam00715309 sub-mode; 0x654410.. sprite templates
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00715317; sRam007152e8; sRam007152ea; cRam00715309

## Behavioral explanation
Giant per-flag HUD icon/animation renderer: for each status bit it positions and blits the matching icon (connecting spinner, error, arrows, per-screen menu markers) using screen id cRam00715317 and cursor sRam007152e8/ea.

## Notes / uncertainty
Single-bit overlay dispatcher (param_1 = one bit of uRam0071530c overlay-active mask) rendering connect spinner/error/signal-bar/position-markers/blink icons. P1(cRam00715315/bRam00715314/sRam00715340) vs P2(...17/...16/...42) split-screen families are symmetric; only representative arms expanded, ~10KB per-screen X-offset tables preserved verbatim in raw. Presentation only, not on wire. Uncertain: exact FUN_00619d90 layer semantics, sprite-buffer colour field, whether bit 0x400000 is reachable.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
