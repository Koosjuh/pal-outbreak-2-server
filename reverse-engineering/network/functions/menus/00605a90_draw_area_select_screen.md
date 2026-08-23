# 0x00605a90 draw_area_select_screen

| field | value |
|---|---|
| Original address | 0x00605a90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605a90 |
| Resolved name | draw_area_select_screen |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005bac80, FUN_0062fea0
**Referenced globals:** bRam006970f4 (area count); 0x6970f6 (area record table); 0x69713a/0x69715d (per-area fields); cRam006c550e/cRam006970a2; uRam006c4b96
**Referenced strings:** 0x6970b2; 0x6970a2
**Referenced opcodes:** —
**State vars:** bRam006970f4

## Behavioral explanation
Draw callback for the area/scenario-select screen: lays out labels and the list of areas (count bRam006970f4, records at 0x6970f6 stride 0x14a8) plus header/footer strings from the menu-string table.

## Notes / uncertainty
Area/room list row callback; only header node (flag3==0 && index==0) draws whole panel from record table 0x6970f6 stride 0x14a8 count bRam006970f4. Matches validated all-areas render. Full record layout between +0x45..+0x67 unproven; purpose of 0x80 stack scratch unclear.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605a90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
