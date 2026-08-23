# 0x0061f0e0 redraw_flags_set_base

| field | value |
|---|---|
| Original address | 0x0061f0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f0e0 |
| Resolved name | redraw_flags_set_base |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00620250, FUN_00620d60, FUN_00623800, FUN_00624850, FUN_00624c70, FUN_00625190, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c

## Behavioral explanation
Sets uRam0071530c = 1 (mark base element visible/dirty).

## Notes / uncertainty
ui_redraw_mask = 1 (overwrite, not OR) — show base element only. 'base' meaning of bit0x1 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f0e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
