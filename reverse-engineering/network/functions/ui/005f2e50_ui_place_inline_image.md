# 0x005f2e50 ui_place_inline_image

| field | value |
|---|---|
| Original address | 0x005f2e50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2e50 |
| Resolved name | ui_place_inline_image |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee610
**Callees:** FUN_005ee220, FUN_005f3230
**Referenced globals:** +0x186 pass; +0xdf6/+0xdf8 element size; +0x16 height; +0xd8ce..+0xd8dc cursors; +0x2500/+0x2502 extents, +0x251a/+0x251c pad
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8ce; +0xd8de

## Behavioral explanation
Reserves/advances space for an inline element of size +0xdf6 (with wrap), or in draw mode renders it via FUN_005ee220; updates line cursors and root extents.

## Notes / uncertainty
Renamed from inline_sprite: places inline image sized +0xdf6/+0xdf8, wrap via f3230, blit via 5ee220, updates root extents. +0xd8de incremented-by-width semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f2e50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
