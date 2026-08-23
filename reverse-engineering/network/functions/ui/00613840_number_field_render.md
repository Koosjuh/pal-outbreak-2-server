# 0x00613840 number_field_render

| field | value |
|---|---|
| Original address | 0x00613840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613840 |
| Resolved name | number_field_render |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_006146e0
**Referenced globals:** ctx+0x41 (edit-active flag); ctx+0x44 (active field ptr); fmt 0x654140
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x41 edit mode; ctx+0x44 active field

## Behavioral explanation
Renders a 5-digit number (from *param_1) right-justified with leading-space suppression; when it's the active edit field (ctx+0x41 set and +0x44 points at it) lays digits at a fixed edit column instead.

## Notes / uncertainty
Editable u16 field: display path right-justifies (sprintf fmt 0x654140), edit path (ctx+0x41 set && ctx+0x44==field) shows all 5 raw digits at 13-col margin. Display-path sprintf dst is stack aliasing.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
