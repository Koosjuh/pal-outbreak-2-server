# 0x001eb33c list_flags_set

| field | value |
|---|---|
| Original address | 0x001eb33c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb33c |
| Resolved name | list_flags_set |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec1f8
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe list flags

## Behavioral explanation
OR-sets bits in the list flags word (+0xe) and returns the new flags.

## Notes / uncertainty
Sticky OR into flags +0xe, returns new flags; latches sub-pool watermark bit in FUN_001ec1f8. Clear path is elsewhere.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb33c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
