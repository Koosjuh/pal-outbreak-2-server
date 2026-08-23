# 0x005af340 ext_query_1b3db0

| field | value |
|---|---|
| Original address | 0x005af340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af340 |
| Resolved name | ext_query_1b3db0 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_005b3790, FUN_005f6b00, FUN_005f6d20, FUN_00606af0, FUN_00606e40, FUN_006075e0, FUN_006076c0, FUN_00608300, FUN_006088b0
**Callees:** FUN_001b3db0, FUN_0061e940
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin thunk returning a byte from external routine EXT_FUN_001b3db0 (base-module library call).

## Notes / uncertainty
Thin thunk returning byte from base-module EXT_FUN_001b3db0 (not in this overlay). Purpose opaque. Corrected callee list: prior record's FUN_0061e940 mis-attributed; only thunk_EXT_FUN_001b3db0 is real. Callers are 2, not 11 as old record listed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
