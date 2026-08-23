# 0x001c3320 netbuf_init_mode6

| field | value |
|---|---|
| Original address | 0x001c3320 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3320 |
| Resolved name | netbuf_init_mode6 |
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
Init for connection mode 6: thin wrapper over FUN_001c2da0(6).

## Notes / uncertainty
Thin wrapper netbuf_ctx_init(6); identical to mode5 except mode constant. Downstream role not captured.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
