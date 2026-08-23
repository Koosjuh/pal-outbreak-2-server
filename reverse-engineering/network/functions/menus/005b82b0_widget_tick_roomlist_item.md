# 0x005b82b0 widget_tick_roomlist_item

| field | value |
|---|---|
| Original address | 0x005b82b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b82b0 |
| Resolved name | widget_tick_roomlist_item |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20
**Referenced globals:** obj+2 (item type); uRam006c45fe (member count); uRam006c4602 / cRam006c4fda / cRam006c4fd8 / cRam006c5495 / cRam006c5498 / cRam006c5499 (assorted counts/cursors); DAT_006928c8 (blink rate)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd3; uRam006c45fe

## Behavioral explanation
Per-frame widget update for room/lobby list items: dispatches on item-type (0x02,0x06,0x08,0x0a,0x11,0x20,0x21,0x22,0x23,...) to set selectable/highlight from various room counts (uRam006c45fe member count, uRam006c4602, cRam006c4fda/d8, cRam006c5495/5498), then computes a blink/alpha value.

## Notes / uncertainty
Big per-type list-row gate + pulsing alpha. Roster count uRam006c45fe (type 0x06, page size 7), plus uRam006c4602 (0x08, size 5) and cRam006c54xx. +0xb 'index_alt' inferred; 0x22/0x23 record layout not owned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b82b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
