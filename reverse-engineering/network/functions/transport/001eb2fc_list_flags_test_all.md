# 0x001eb2fc list_flags_test_all

| field | value |
|---|---|
| Original address | 0x001eb2fc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb2fc |
| Resolved name | list_flags_test_all |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec1f8, FUN_001ec9e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe list flags (e.g. watermark-latched bit)

## Behavioral explanation
Tests whether all bits of the mask are set in the list flags word (+0xe).

## Notes / uncertainty
(flags & mask)==mask test on +0xe; sub-pool watermark/disable latch guard in FUN_001ec1f8. Concrete bit meanings live in pool code.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb2fc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
