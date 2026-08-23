# 0x001ed5dc pktbuf_inc_f20

| field | value |
|---|---|
| Original address | 0x001ed5dc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed5dc |
| Resolved name | pktbuf_inc_f20 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x20

## Behavioral explanation
Increments counter buf+0x20 by 1 (bump retransmit/attempt count).

## Notes / uncertainty
++attempt counter +0x20 (void, no return). Caller FUN_001d5460 bounds it vs conn+0x518 max-attempts -> err 300 on exceed. Post-inc-then-check behavior unambiguous.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed5dc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
