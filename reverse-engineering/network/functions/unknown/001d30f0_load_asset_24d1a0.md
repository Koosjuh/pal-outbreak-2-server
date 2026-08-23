# 0x001d30f0 load_asset_24d1a0

| field | value |
|---|---|
| Original address | 0x001d30f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d30f0 |
| Resolved name | load_asset_24d1a0 |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001d31b0
**Referenced globals:** 0x34357a stage id; 0x24d1a0 path fmt
**Referenced strings:** (path fmt @0x24d1a0)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Formats path 0x24d1a0 with stage id and loads via 0x1d31b0 (slot 1).

## Notes / uncertainty
Sibling of 0x1d30b0: fmt 0x24d1a0 w/ stage id, slot 1. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d30f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
