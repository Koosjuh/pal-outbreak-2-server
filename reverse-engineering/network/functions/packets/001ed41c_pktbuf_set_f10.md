# 0x001ed41c pktbuf_set_f10

| field | value |
|---|---|
| Original address | 0x001ed41c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed41c |
| Resolved name | pktbuf_set_f10 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e3a3c
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x10

## Behavioral explanation
Setter: writes buf+0x10 = param_2, returns it.

## Notes / uncertainty
Setter +0x10 (build path FUN_001e3a3c); mirror of get_f10 recv read. [inferred] seq/msg-id.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed41c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
