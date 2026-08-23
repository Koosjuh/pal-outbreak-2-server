# 0x001ed474 pktbuf_set_f14

| field | value |
|---|---|
| Original address | 0x001ed474 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed474 |
| Resolved name | pktbuf_set_f14 |
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
**State vars:** buf+0x14

## Behavioral explanation
Setter: writes buf+0x14 = param_2, returns it.

## Notes / uncertainty
Setter +0x14 (init/enqueue FUN_001d6468). [inferred] base RTO/due-time component.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed474.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
