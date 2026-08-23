# 0x0062bb20 roster_screen_enter

| field | value |
|---|---|
| Original address | 0x0062bb20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062bb20 |
| Resolved name | roster_screen_enter |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062ba70
**Callees:** FUN_005af400, FUN_00618b60, FUN_00629d00, FUN_0062cd20
**Referenced globals:** +0x10b8 scratch record; +0x12c2 member-list buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Enter handler for the roster/member-list screen: zeroes the +0x10b8 (0x20a) and +0x12c2 (0x19e) member buffers, builds widgets, bumps state.

## Notes / uncertainty
Straight-line roster-screen init; zeroes member arrays +0x10b8(0x20a)/+0x12c2(0x19e) then builds widgets. Element layout of 0x20a region and widget-group id meanings (0/3/4) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062bb20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
