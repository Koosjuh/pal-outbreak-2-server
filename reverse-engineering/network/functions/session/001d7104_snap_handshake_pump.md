# 0x001d7104 snap_handshake_pump

| field | value |
|---|---|
| Original address | 0x001d7104 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d7104 |
| Resolved name | snap_handshake_pump |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001d6ee0, FUN_001d94b0, FUN_001eb2d4
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x80 handshake state; conn+0x7c last-send ts; conn+0x4fc now; conn+0x51c keepalive interval

## Behavioral explanation
Connection handshake/keepalive state machine over conn+0x80 (states 1/2/3): on timer expiry sends the prepare message (001d6ee0) and advances state, else fires the periodic keepalive (001d94b0).

## Notes / uncertainty
Handshake driver over conn+0x80: state2 resends PREPARE (6ee0) after 500 ticks when window free -> state3, else timeout(0x51c)->94b0; states1&3 only watch the timeout interval->94b0. Uncertainty: tick timebase; FUN_001eb2d4 predicate.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d7104.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
