# 0x001ebda4 buf_get_prev_dup

| field | value |
|---|---|
| Original address | 0x001ebda4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebda4 |
| Resolved name | buf_get_prev_dup |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the word at +4 — duplicate of buf_get_field4 (prev link).

## Notes / uncertainty
Renamed from node_get_field4_dup: byte-identical twin of buf_get_prev (+0x4).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebda4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
