# 0x001d94b0 snap_session_notify_timeout

| field | value |
|---|---|
| Original address | 0x001d94b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d94b0 |
| Resolved name | snap_session_notify_timeout |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d7104
**Callees:** —
**Referenced globals:** conn+0x5b8(session-result cb); conn+0x7c(timeout); conn+0x80(state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x80(conn-state); 0x7c(timeout)

## Behavioral explanation
Synthesizes a session-result descriptor (status 0x14) to the app callback at conn+0x5b8 and resets the connect state machine (0x7c/0x80=0).

## Notes / uncertainty
Timeout twin: forges an op-0x27 session-result event with status 0x14 to conn+0x5b8 callback, then resets conn+0x7c/0x80=0. Every timeout leg of the handshake pump calls it. Uncertainty: payload {1,0x14} field semantics.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d94b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
