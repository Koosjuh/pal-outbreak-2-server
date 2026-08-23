# 0x0061ddd0 connect_msg_set

| field | value |
|---|---|
| Original address | 0x0061ddd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ddd0 |
| Resolved name | connect_msg_set |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061ded0
**Callees:** —
**Referenced globals:** uRam0071535d next-state; uRam0071535c timer=0x6e
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0071535c; uRam0071535d

## Behavioral explanation
Sets the connect-machine's next-state byte and a 0x6e-frame timer (message dwell) with no retry fields.

## Notes / uncertainty
Lighter sibling of _timed: sets next-state 71535d and 0x6e-frame dwell 71535c only (no msg-id/param/SM-timer kick). Exact. Legal next-state values defined by consumer FUN_0061ded0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ddd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
