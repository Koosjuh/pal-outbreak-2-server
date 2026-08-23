# 0x005f70a0 reset_wait_overlay_state

| field | value |
|---|---|
| Original address | 0x005f70a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f70a0 |
| Resolved name | reset_wait_overlay_state |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6b00, FUN_005f6d20
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x429; param+0x42a

## Behavioral explanation
Zeroes the wait-overlay sub-state bytes +0x429 and +0x42a before the overlay SM runs.

## Notes / uncertainty
Zeroes wait-overlay SM step +0x429 and aux +0x42a. Trivial init for wait_overlay_sm.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f70a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
