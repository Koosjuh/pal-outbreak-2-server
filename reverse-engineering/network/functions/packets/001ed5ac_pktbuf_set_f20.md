# 0x001ed5ac pktbuf_set_f20

| field | value |
|---|---|
| Original address | 0x001ed5ac |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed5ac |
| Resolved name | pktbuf_set_f20 |
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
**State vars:** buf+0x20

## Behavioral explanation
Setter: writes buf+0x20 = param_2, returns it.

## Notes / uncertainty
Setter +0x20 (attempt counter). Behavior trivial/certain but NO indexed caller -> reset/init role inferred (normal path uses inc_f20).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed5ac.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
