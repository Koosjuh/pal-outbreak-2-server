# 0x001e3100 socket_bind

| field | value |
|---|---|
| Original address | 0x001e3100 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e3100 |
| Resolved name | socket_bind |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_00103de8, FUN_00114ac8, FUN_001e2a28, FUN_001efee0
**Referenced globals:** PTR_0025b798 table; 0x259628 log
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state -1/0x7f; slot+2 type

## Behavioral explanation
bind(): requires sockaddr len 0x10; for stream(type1) stashes addr(+0xe)/port(+0x10); for dgram(type2) opens a bound endpoint via FUN_001efee0 and moves to established(0x7f).

## Notes / uncertainty
bind(): addrlen 0x10, state -1. Stream just stashes addr(+0x1c)/port(+0x20); dgram opens UDP now (FUN_001efee0)->state 0x7f. errno 0xe/0x6b/0x6c/0x7d/0xffff. sockaddr {fam@0,port@2,addr@4} inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e3100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
