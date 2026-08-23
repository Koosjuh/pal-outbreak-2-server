# 0x005e1f30 rect_clip_to_screen

| field | value |
|---|---|
| Original address | 0x005e1f30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e1f30 |
| Resolved name | rect_clip_to_screen |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e19b0, FUN_005e1a30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clips a rect (by pointer) to 0..640/0..448, returning 0 if fully off-screen else 1.

## Notes / uncertainty
In-place rect clip to 0..640/0..448, returns 1 visible / 0 culled via short-circuit ladder. Fully transcribed, deterministic; only unvalidated at runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e1f30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
