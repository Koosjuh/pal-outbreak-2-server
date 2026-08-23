# 0x001e2ffc socket_listen

| field | value |
|---|---|
| Original address | 0x001e2ffc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2ffc |
| Resolved name | socket_listen |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00103de8, FUN_001e2a28, FUN_001ef690
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state -1 -> 0xff5 listening

## Behavioral explanation
listen(): on an unbound stream slot (state -1) opens a passive endpoint via FUN_001ef690 using stored addr(+0xe)/port(+0x10) and transitions state to 0xff5 (listening).

## Notes / uncertainty
listen(): unbound slot (+4==-1) -> passive_open (FUN_001ef690) using stashed addr/port -> state 0xff5. Negative passive-open code returned raw with errno unset.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2ffc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
