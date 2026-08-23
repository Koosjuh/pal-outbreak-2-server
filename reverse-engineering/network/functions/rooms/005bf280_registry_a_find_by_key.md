# 0x005bf280 registry_a_find_by_key

| field | value |
|---|---|
| Original address | 0x005bf280 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf280 |
| Resolved name | registry_a_find_by_key |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bf740, FUN_005c70e0
**Callees:** —
**Referenced globals:** 0x6fec28 registry A (10x0x24)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Linear-searches registry A (10 entries, stride 0x24 @0x6fec28) for entry whose key word == param; returns index or -1.

## Notes / uncertainty
Linear key lookup over registry A (10 slots, stride 0x24, key col @0x6fec28); ret index 0..9 or -1. Only +0x00 key column exercised; full slot layout unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf280.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
