# 0x005f2b10 ui_place_hrule_widget

| field | value |
|---|---|
| Original address | 0x005f2b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2b10 |
| Resolved name | ui_place_hrule_widget |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee010
**Callees:** FUN_005d9350, FUN_005f3230
**Referenced globals:** +0x186 pass; +0x188 root idx; +0x18 row-unit; +0x16 height; +0xd8ce..+0xd8dc cursors; +0x2500/+0x2502 extents
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8d2; +0xd8de

## Behavioral explanation
Reserves/advances a fixed-height row (height=+0x18*8+0x18) with wrap check, or in draw mode emits it via FUN_005d9350; updates line/extent cursors.

## Notes / uncertainty
Renamed from fixed_row: fixed-height element (sizeUnit*8+0x18) with wrap check, draws via 5d9350, 20px root height clamp. hr-vs-generic-box distinction inferred from primitive.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f2b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
