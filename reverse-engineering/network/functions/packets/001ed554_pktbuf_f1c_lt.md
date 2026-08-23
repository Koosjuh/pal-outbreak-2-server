# 0x001ed554 pktbuf_f1c_lt

| field | value |
|---|---|
| Original address | 0x001ed554 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed554 |
| Resolved name | pktbuf_f1c_lt |
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
**State vars:** buf+0x1c

## Behavioral explanation
Predicate: returns buf+0x1c < param_2 (seq/counter less-than comparison).

## Notes / uncertainty
Signed predicate f1c < param_2. Behavior certain but NO indexed caller -> purpose (backoff ceiling vs sort order) inferred from field role; may be inlined-only/dead.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed554.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
