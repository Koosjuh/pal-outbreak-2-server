# 0x0061ddf0 connect_timer_draw

| field | value |
|---|---|
| Original address | 0x0061ddf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ddf0 |
| Resolved name | connect_timer_draw |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061ded0
**Callees:** —
**Referenced globals:** sRam007152e6 countdown; 0x669c28 number format
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** sRam007152e6

## Behavioral explanation
Renders the connect/matchmaking countdown number (sRam007152e6/0x1e seconds) centered on screen, decrementing the timer.

## Notes / uncertainty
Ticks+draws connect countdown sRam007152e6 (decrement floored at 0), displays /0x1e (30fps->seconds) centered grey 0x80808080 at Y=0x160 via format 0x669c28. Width-advance constant heuristic.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ddf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
