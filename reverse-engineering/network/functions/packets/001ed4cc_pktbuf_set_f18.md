# 0x001ed4cc pktbuf_set_f18

| field | value |
|---|---|
| Original address | 0x001ed4cc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed4cc |
| Resolved name | pktbuf_set_f18 |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x18

## Behavioral explanation
Setter: writes buf+0x18 = param_2, returns it.

## Notes / uncertainty
Setter +0x18 (init FUN_001d6468). [inferred] send timestamp.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed4cc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
