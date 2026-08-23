# 0x001c3300 netbuf_init_mode5

| field | value |
|---|---|
| Original address | 0x001c3300 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3300 |
| Resolved name | netbuf_init_mode5 |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c2da0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Init for connection mode 5: thin wrapper over FUN_001c2da0(5).

## Notes / uncertainty
Thin wrapper netbuf_ctx_init(5); bare slot, mode byte only distinguishing state. Downstream role of mode5 vs 6 not captured.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
