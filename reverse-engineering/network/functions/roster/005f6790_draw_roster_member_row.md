# 0x005f6790 draw_roster_member_row

| field | value |
|---|---|
| Original address | 0x005f6790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6790 |
| Resolved name | draw_roster_member_row |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fdf0
**Referenced globals:** 0x649720 (x-coord table); 0x70a164 (per-member 0x30-stride data); 0x70a17c (member flag column)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+3 (member index)

## Behavioral explanation
Draw callback for one player-list row: renders the member name string (table 0x649750) and copies that member's 0x10-byte record from the 0x70a164 table (stride 0x30) to draw the player's icon/portrait; highlights the local slot (iVar2+0xc == slot).

## Notes / uncertainty
Draw cb for one lobby row: row number, name (0x70a164 stride 0x30), status glyph (flag bit0), highlight on list+0xc selected. count==0 path writes an uninitialized running-X to +0x26 (decompiler/ABI artifact, non-critical).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
