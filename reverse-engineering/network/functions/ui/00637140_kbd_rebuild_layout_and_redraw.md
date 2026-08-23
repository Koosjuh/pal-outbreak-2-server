# 0x00637140 kbd_rebuild_layout_and_redraw

| field | value |
|---|---|
| Original address | 0x00637140 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637140 |
| Resolved name | kbd_rebuild_layout_and_redraw |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_00631100, FUN_006312c0, FUN_00631560, FUN_00631670, FUN_00632330, FUN_00635ab0, FUN_00635bb0, FUN_00635f80, FUN_00636f90, FUN_006375d0
**Callees:** FUN_00634470, FUN_00637710
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Redraw helper: rebuilds the active layout pointer (FUN_00637710) then triggers the redraw (FUN_00634470); called after every key/state change.

## Notes / uncertainty
2-call refresh glue: recompute geometry FUN_00637710 then request redraw FUN_00634470. 11 callers (every action handler). Split of the two callees inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637140.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
