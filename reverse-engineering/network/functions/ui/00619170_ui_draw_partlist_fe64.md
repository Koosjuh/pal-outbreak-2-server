# 0x00619170 ui_draw_partlist_fe64

| field | value |
|---|---|
| Original address | 0x00619170 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619170 |
| Resolved name | ui_draw_partlist_fe64 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00618c90
**Callees:** FUN_006381e0
**Referenced globals:** PTR_DAT_0066fe64 part-list
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws a fixed part-list (PTR_DAT_0066fe64) as a run of quads, walking 0x14-byte records until terminator.

## Notes / uncertainty
Draws fixed global part-list PTR_DAT_0066fe64 as opaque-black (0xff000000) quads via FUN_006381e0(ctx=-30), 0x14 stride until part[0]==0. Gated by cRam6c5538. Identity of list + ctx handle unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
