# 0x00627a20 roster_display_tick_timers

| field | value |
|---|---|
| Original address | 0x00627a20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627a20 |
| Resolved name | roster_display_tick_timers |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** —
**Referenced globals:** 0x715510 slot-inuse; 0x715512 slot-timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Per-frame tick: decrements the per-slot countdown at 0x715512 for every in-use roster display slot (50).

## Notes / uncertainty
Per-frame decrement of s16 highlight countdown (+0x12) for in-use display slots, clamped at 0. Mechanics fully determined; visual meaning of timer inferred from writer 0x627b00.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627a20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
