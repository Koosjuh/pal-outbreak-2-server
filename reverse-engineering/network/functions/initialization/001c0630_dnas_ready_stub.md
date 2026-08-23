# 0x001c0630 dnas_ready_stub

| field | value |
|---|---|
| Original address | 0x001c0630 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0630 |
| Resolved name | dnas_ready_stub |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0100
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stub returning constant 1 (always-ready poll used by boot state 1).

## Notes / uncertainty
Returns constant 1; caller advances only on 2/4, so state-1 gate STATICALLY PARKS -> DNAS ready-gate inert in this build. Whether a real poll is patched at runtime is open.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
