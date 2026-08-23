# 0x001c0670 trace_log_stub

| field | value |
|---|---|
| Original address | 0x001c0670 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0670 |
| Resolved name | trace_log_stub |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c0e60, FUN_001c2770
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Variadic no-op trace/log sink (compiled-out); called with fmt-ptr + fields by dispatchers FUN_001c0e60 and FUN_001c2770.

## Notes / uncertainty
Empty body but variadic (fmt,...) call sites from boot dispatchers = compiled-out trace logger. Original format strings elided.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
