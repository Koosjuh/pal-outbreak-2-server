# 0x006050d0 draw_roster_member_row

| field | value |
|---|---|
| Original address | 0x006050d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006050d0 |
| Resolved name | draw_roster_member_row |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005af810, FUN_0062fdf0
**Referenced globals:** 0x70b470 (row flag); 0x70b4c0 (member id); 0x70b4d0 (status); cRam006c5497/cRam006c5498; &DAT_00649ff0; 0x64a048 (fmt)
**Referenced strings:** fmt @0x64a048
**Referenced opcodes:** —
**State vars:** cRam006c5497; cRam006c5498

## Behavioral explanation
Draw callback for a single roster row: renders slot number, the member's 0x10-byte id/name from 0x70b4c0, highlights the local player's row (cRam006c5497==row), and draws a status glyph keyed by 0x70b4d0.

## Notes / uncertainty
Per-row roster draw: slot number, 16-byte id/name from 0x70b4c0, local-player highlight (cRam006c5497==row->0xf), status glyph via FUN_0062fdf0(5)+status*0xC indexed by 0x70b4d0. FUN_005af810 clip predicate and glyph-descriptor layout inferred; pen-x store only meaningful on active-list path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006050d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
