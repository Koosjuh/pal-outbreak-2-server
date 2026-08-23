# 0x001ed0bc pktbuf_alloc_init

| field | value |
|---|---|
| Original address | 0x001ed0bc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed0bc |
| Resolved name | pktbuf_alloc_init |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ed168
**Callees:** FUN_001eba40, FUN_001ed034
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a packet buffer (FUN_001eba40 with size/flags args), inits it (FUN_001ed034), stores handle to *param_1.

## Notes / uncertainty
Alloc (FUN_001eba40, size/aux) + init (FUN_001ed034); publishes handle to *out only if both rc==0. OOM error 0xffffe4a9. size-class encoding (depends on FUN_001e1e4c) unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed0bc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
