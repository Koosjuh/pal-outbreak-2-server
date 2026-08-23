# 0x005e0510 draw_line_clamped

| field | value |
|---|---|
| Original address | 0x005e0510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0510 |
| Resolved name | draw_line_clamped |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e2760
**Callees:** FUN_005dd960
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a line/edge via FUN_005dd960 only if endpoints are on-screen (>=0, <=640/448).

## Notes / uncertainty
Cull-not-clip line wrapper: draws via FUN_005dd960 only if p5>=0,p6>=0,x<=640,y<=448. FUN_005dd960 called with no explicit args in decompile (reg passthrough); exact endpoint/color arg mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
