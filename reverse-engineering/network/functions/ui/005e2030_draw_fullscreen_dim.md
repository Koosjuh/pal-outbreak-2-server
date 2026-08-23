# 0x005e2030 draw_fullscreen_dim

| field | value |
|---|---|
| Original address | 0x005e2030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e2030 |
| Resolved name | draw_fullscreen_dim |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e2060
**Callees:** FUN_005e0440
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a full-screen (0,0,640,448) semi-transparent overlay quad via FUN_005e0440.

## Notes / uncertainty
Zero-arg wrapper: one 640x448 quad at ARGB 0x80010101 (~50% dim) as modal backdrop. Float consts decode exactly to 640/448. Cosmetic; blend eq unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e2030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
