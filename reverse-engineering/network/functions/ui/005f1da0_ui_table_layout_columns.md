# 0x005f1da0 ui_table_layout_columns

| field | value |
|---|---|
| Original address | 0x005f1da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f1da0 |
| Resolved name | ui_table_layout_columns |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eacd0
**Callees:** FUN_005f16b0, FUN_005f1a80
**Referenced globals:** +0x186 pass match; node+0x1c width, +0x20/+0x22 min/pref, +0x28 x, +0x30/+0x32 pad/margin, +0x46/+0x47 flags/colspan
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Full table column layout: walks rows building min/pref column-edge arrays (max 32, handling colspans with flag 8), reconciles them, then writes final per-cell x/width back onto nodes.

## Notes / uncertainty
Top-level table auto-layout: builds min/pref edge arrays over rows (colspan tag 0x8), reconciles (f1a80), fits (f16b0), writes per-cell x/width. Pass-B span index bookkeeping kept faithful; table spacing field names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f1da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
