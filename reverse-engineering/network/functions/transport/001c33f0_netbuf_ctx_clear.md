# 0x001c33f0 netbuf_ctx_clear

| field | value |
|---|---|
| Original address | 0x001c33f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c33f0 |
| Resolved name | netbuf_ctx_clear |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60
**Referenced globals:** 0x365ac0 conn-obj
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365ac0

## Behavioral explanation
Zeroes the connection-object header (0x365ac0, 0xec bytes).

## Notes / uncertainty
Zeroes netbuf_ctx header (0x365ac0, 0xec) — same region/size as ctor memset; teardown/idle (ready=0). No direct callers in set.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c33f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
