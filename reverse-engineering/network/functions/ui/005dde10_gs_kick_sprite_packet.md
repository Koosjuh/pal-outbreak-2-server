# 0x005dde10 gs_kick_sprite_packet

| field | value |
|---|---|
| Original address | 0x005dde10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dde10 |
| Resolved name | gs_kick_sprite_packet |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ddb40
**Callees:** —
**Referenced globals:** DAT_70000028/30/38/40/48 (GS GIF packet); iRam0028a458/a450 (screen dims); iRam0028a324 (draw-disable gate); fRam00289f74 (Z)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0028a324 (render enable)

## Behavioral explanation
Builds a GIF/GS packet at 0x70000000 (UV, XYZ, color) scaling by screen-width ratio and kicks it via func_0x0018a650 to draw a textured sprite.

## Notes / uncertainty
Already fully reconstructed; verified rec[8]-- mutation and 12.4 fixed-point/width-scale/Z-clamp. GIF register order (UV vs ST) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dde10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
