# 0x005f2940 ui_place_form_control

| field | value |
|---|---|
| Original address | 0x005f2940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2940 |
| Resolved name | ui_place_form_control |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005edc40
**Callees:** FUN_005ed6e0
**Referenced globals:** +0x186 pass; +0x4e4 control type; +0x16 running height; +0x2500/+0x2502 extents, +0x251e cell offset; +0xd8ce/+0xd8d0 cursors
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8de

## Behavioral explanation
Reserves/advances layout space for a widget whose size depends on control type +0x4e4 (gauge/list/etc.), or in draw mode positions it via FUN_005ed6e0.

## Notes / uncertainty
Renamed from sized_widget: reserves space for a form control sized by type +0x4e4 (text 8px/char, toggle 20px fixed). Type->widget mapping inferred from width formulas.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f2940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
