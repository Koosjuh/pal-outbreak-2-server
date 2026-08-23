# 0x001edfd0 pktbuf_f28_eq

| field | value |
|---|---|
| Original address | 0x001edfd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001edfd0 |
| Resolved name | pktbuf_f28_eq |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x28

## Behavioral explanation
Predicate: returns buf+0x28 == param_2 (match on the +0x28 id/channel field).

## Notes / uncertainty
Comparator buf->f28==key; likely a list-search comparator passed by pointer. No recorded caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001edfd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
