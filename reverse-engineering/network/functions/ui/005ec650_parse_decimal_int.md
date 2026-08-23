# 0x005ec650 parse_decimal_int

| field | value |
|---|---|
| Original address | 0x005ec650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec650 |
| Resolved name | parse_decimal_int |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8dc0, FUN_005e8e00, FUN_005e9580, FUN_005e95e0, FUN_005e96d0, FUN_005e9710, FUN_005e9b70, FUN_005e9ef0, FUN_005ea990, FUN_005eaa10, FUN_005eaa70, FUN_005eab70, FUN_005ebaf0, FUN_005ebb50, FUN_005ebbd0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a decimal integer from an ASCII string (accumulates digits 0-9).

## Notes / uncertainty
Lenient atoi over strlen(token); non-digits skipped not terminating. strlen(func_0x0010a050) identity inferred. Behavior fully determined; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
