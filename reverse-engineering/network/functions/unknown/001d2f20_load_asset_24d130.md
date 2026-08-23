# 0x001d2f20 load_asset_24d130

| field | value |
|---|---|
| Original address | 0x001d2f20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2f20 |
| Resolved name | load_asset_24d130 |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d31b0
**Referenced globals:** 0x24d130 path
**Referenced strings:** (path @0x24d130)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads a fixed-name asset (0x24d130) via the generic loader 0x1d31b0.

## Notes / uncertainty
Trivial wrapper: FUN_001d31b0(0x24d130, slot0). Only uncertainty is the concrete asset name. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2f20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
