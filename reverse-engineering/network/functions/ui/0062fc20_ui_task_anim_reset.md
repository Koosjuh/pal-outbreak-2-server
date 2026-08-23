# 0x0062fc20 ui_task_anim_reset

| field | value |
|---|---|
| Original address | 0x0062fc20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fc20 |
| Resolved name | ui_task_anim_reset |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062f990, FUN_0062fa80
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI helper: resets a widget's animation state — phase +0x3a=0, color +0x2c=0xffffffff, sets visible bit 0x80 in +0x24, clears +9.

## Notes / uncertainty
Resets blink-anim baseline (phase 0, color opaque white, visible bit, restart clear). Companion init to fc40.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fc20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
