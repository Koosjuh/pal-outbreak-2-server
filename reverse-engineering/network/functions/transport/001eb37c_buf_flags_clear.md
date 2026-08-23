# 0x001eb37c buf_flags_clear

| field | value |
|---|---|
| Original address | 0x001eb37c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb37c |
| Resolved name | buf_flags_clear |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec9e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe list flags

## Behavioral explanation
AND-clears bits in the list flags word (+0xe) and returns the new flags.

## Notes / uncertainty
AND-NOT of mask into buf_node flags word (+0x0e); renamed from list_flags_clear since it operates on buffer nodes (twin of buf_flags_set/test). Specific bit meanings (reliable 0x8000/who bits) unproven for this internal word; sole caller FUN_001ec9e0 (pool recycle).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb37c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
