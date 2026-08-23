# 0x001e332c socket_connect

| field | value |
|---|---|
| Original address | 0x001e332c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e332c |
| Resolved name | socket_connect |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00103de8, FUN_001e2a28, FUN_001e4bec, FUN_001ef9a0
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0xff4/0x7f/0xff2; slot+2 type1

## Behavioral explanation
connect() for a stream socket: advances the state machine (e4bec) and, when in 0xff4/0x7f, issues the connect via FUN_001ef9a0, transitioning to 0xff2 on pending.

## Notes / uncertainty
connect() stream only (type 1): pump SM, from 0xff4/0x7f issue FUN_001ef9a0; -1 -> 0xff2 connecting. errno 0xe/9/0x6b. State 0xff4 role (idle-connectable) inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e332c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
