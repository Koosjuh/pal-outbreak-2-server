# 0x005dda30 gs_draw_line

| field | value |
|---|---|
| Original address | 0x005dda30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dda30 |
| Resolved name | gs_draw_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e0440, FUN_005e19b0, FUN_005e1a30, FUN_005e1aa0, FUN_005e1da0
**Callees:** FUN_005dd920
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Snaps X coords onto a 5-unit grid then packs 4 floats + color and submits a line draw via func_0x001a2800.

## Notes / uncertainty
Already fully reconstructed; verified against raw (grid-snap + short-pack + kick). No change needed. Color channel order and FUN_005dd920 arg2 unproven at runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dda30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
