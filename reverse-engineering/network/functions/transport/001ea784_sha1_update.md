# 0x001ea784 sha1_update

| field | value |
|---|---|
| Original address | 0x001ea784 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ea784 |
| Resolved name | sha1_update |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ea8e8
**Callees:** FUN_001e5a00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Feeds param_3 bytes at param_2 into the SHA-1 context by repeatedly calling the transform (flag=0, no finalize).

## Notes / uncertainty
Thin driver: loops absorb core (finalize=0) until count consumed. Certain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ea784.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
