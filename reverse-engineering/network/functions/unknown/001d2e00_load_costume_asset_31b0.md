# 0x001d2e00 load_costume_asset_31b0

| field | value |
|---|---|
| Original address | 0x001d2e00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2e00 |
| Resolved name | load_costume_asset_31b0 |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001d31b0
**Referenced globals:** struct+0xc8c char id; 0x24d120 path fmt
**Referenced strings:** (path fmt @0x24d120)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Resolves a costume/char id (0x61dca0), formats a path (fmt 0x24d120) and loads it via 0x1d31b0.

## Notes / uncertainty
Costume/variant loader: selector +0xc8c (-1 skip), resolve via func_0x61dca0, register via func_0x72c7a0, path fmt 0x24d120, load via FUN_001d31b0. No callers; external thunks undecoded. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
