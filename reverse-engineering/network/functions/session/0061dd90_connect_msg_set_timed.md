# 0x0061dd90 connect_msg_set_timed

| field | value |
|---|---|
| Original address | 0x0061dd90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061dd90 |
| Resolved name | connect_msg_set_timed |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061ded0
**Callees:** —
**Referenced globals:** uRam0071535d next-state; uRam0071535e msg id; uRam0071535c timer=100; uRam007152e4 retry; uRam007152e6
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0071535c; uRam0071535d

## Behavioral explanation
Sets the connect-machine's on-screen message/next-state and a 100-frame display timer plus a retry count.

## Notes / uncertainty
Schedules a timed connect-status message: next-state 71535d, param 71535e, 100-frame dwell 71535c, SM timer 7152e4=8, msg id 7152e6=0x3a2. Exact stores. 0x3a2 as a string/message id inferred (not cross-refed to table).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061dd90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
