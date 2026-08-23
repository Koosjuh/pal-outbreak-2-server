# 0x001d9550 snap_session_notify_connected

| field | value |
|---|---|
| Original address | 0x001d9550 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d9550 |
| Resolved name | snap_session_notify_connected |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d9f78
**Callees:** FUN_001d507c
**Referenced globals:** conn+0x5b8(session-result cb); conn+0x7c; conn+0x80
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x80(conn-state); 0x7c

## Behavioral explanation
Delivers a session event (status 1) carrying peer IP(param+0x30)/addr(+0x3c)/port(+0x40, byteswapped) to the conn+0x5b8 callback; calls FUN_001d507c to record the port, then clears state.

## Notes / uncertainty
Success twin: delivers op-0x27 event status=1 carrying peer fields (reply+0x30/+0x3c/+0x40, port bswapped) to conn+0x5b8, records port via FUN_001d507c, resets handshake. Called from app dispatch FUN_001d9f78 on connect reply. Uncertainty: connect-reply struct layout (produced by 001d9678).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d9550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
