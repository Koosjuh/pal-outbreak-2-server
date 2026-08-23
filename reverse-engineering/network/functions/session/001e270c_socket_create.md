# 0x001e270c socket_create

| field | value |
|---|---|
| Original address | 0x001e270c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e270c |
| Resolved name | socket_create |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_00103de8, FUN_001e2654, FUN_001e4bec
**Referenced globals:** PTR_0025b798 socket table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** slot+2 type(1/2); slot state 0xffff/-1

## Behavioral explanation
socket()-like allocator: validates domain(==2) and type(1=stream/2=dgram), reaps closed slots, claims the first free slot in the table, stamps type and flushes it.

## Notes / uncertainty
socket(): domain==2, type 1 stream/2 dgram, scans 64-slot table @PTR_0025b798 (stride 0x24), services active (+2==1) & claims free (+2==-1); errno 0x60/0x6c/0x6d. Corrected slot struct: +2=type/alloc, +4=conn-state.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e270c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
