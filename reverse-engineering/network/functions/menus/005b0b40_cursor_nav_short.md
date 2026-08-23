# 0x005b0b40 cursor_nav_short

| field | value |
|---|---|
| Original address | 0x005b0b40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0b40 |
| Resolved name | cursor_nav_short |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00600200
**Callees:** FUN_005b14b0
**Referenced globals:** 0x6c462a pad button-char latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Identical cursor-navigation-with-repeat logic as cursor_nav_byte but over a 16-bit (ushort) index.

## Notes / uncertainty
ushort variant of cursor_nav_byte, identical control flow (for >255-entry lists). Same crossed horizontal guard chars.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0b40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
