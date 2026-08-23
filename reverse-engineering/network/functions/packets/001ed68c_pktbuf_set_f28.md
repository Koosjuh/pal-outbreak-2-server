# 0x001ed68c pktbuf_set_f28

| field | value |
|---|---|
| Original address | 0x001ed68c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed68c |
| Resolved name | pktbuf_set_f28 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468, FUN_001d6988
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x28

## Behavioral explanation
Setter: writes buf+0x28 = param_2, returns it.

## Notes / uncertainty
Setter counterpart to get_f28; stamps +0x28 during reliable send/recv assembly. Semantic inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed68c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
