# 0x005fe140 scenario_cursor_widget_cb

| field | value |
|---|---|
| Original address | 0x005fe140 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe140 |
| Resolved name | scenario_cursor_widget_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af810, FUN_005bac80, FUN_005bace0
**Referenced globals:** 0x6c4b96 selected index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4b96

## Behavioral explanation
Per-frame cursor widget callback: positions the scenario-row cursor sprite from index uRam006c4b96 (offset 0x150 + idx*9).

## Notes / uncertainty
Scenario-row cursor sprite: peer of 0x5fcba0, stateless, x=slot*9+0x150,y=0x136 from uRam006c4b96. Same untraced helper chain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe140.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
