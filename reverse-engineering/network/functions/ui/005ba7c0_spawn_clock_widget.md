# 0x005ba7c0 spawn_clock_widget

| field | value |
|---|---|
| Original address | 0x005ba7c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba7c0 |
| Resolved name | spawn_clock_widget |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af840, FUN_005f8340
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a display node with callback FUN_005ba8d0 (the clock/elapsed-time widget).

## Notes / uncertainty
Allocs a sprite node, active=1, cb=clock_widget_cb(005ba8d0); no-op if 64-slot table full. Non-net UI.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba7c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
