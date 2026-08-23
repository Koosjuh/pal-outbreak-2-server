# 0x001ed524 pktbuf_set_f1c

| field | value |
|---|---|
| Original address | 0x001ed524 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ed524 |
| Resolved name | pktbuf_set_f1c |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001e180c, FUN_001e3a3c
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf+0x1c

## Behavioral explanation
Setter: writes buf+0x1c = param_2, returns it.

## Notes / uncertainty
Setter +0x1c; FUN_001d5460 does set_f1c(get_f1c+200) linear backoff. Units of 200 (ms/ticks) unknown; build-side writes may set initial/header value.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ed524.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
