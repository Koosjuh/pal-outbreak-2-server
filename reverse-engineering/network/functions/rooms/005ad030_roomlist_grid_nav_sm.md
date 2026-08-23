# 0x005ad030 roomlist_grid_nav_sm

| field | value |
|---|---|
| Original address | 0x005ad030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad030 |
| Resolved name | roomlist_grid_nav_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ace00
**Callees:** FUN_005ad350, FUN_005adc80, FUN_005af2f0, FUN_005af840, FUN_005b14b0, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005b9110, FUN_005bfa70
**Referenced globals:** screen obj +0xf(substate); +0x16(timer); +0x907(cursor); +0x992(busy); +0x45a
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-screen 1 state machine: handles D-pad navigation (FUN_005b14b0 direction masks) over a list, moving cursor 0x907 with wrap, and on select calls FUN_005ad350 to enter an entry.

## Notes / uncertainty
Renamed from list_cursor_nav_sm. 5x2 grid nav SM (cursor +0x907, rows of 5, +-5 row moves); pad masks 0x40004/0x80008/0x10001/0x20002/0x10/0x210; state3 calls FUN_005ad350 to select. Direction->mask mapping inferred from cursor math.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
