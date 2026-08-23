# 0x005bff80 get_short_0x6ce5c2

| field | value |
|---|---|
| Original address | 0x005bff80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bff80 |
| Resolved name | get_short_0x6ce5c2 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc0c0, FUN_0062e9b0, FUN_0062edc0
**Callees:** —
**Referenced globals:** 0x6ce5c2 roster field (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 16-bit global field 0x6ce5c2 into out-ptr.

## Notes / uncertainty
Singleton u16 scalar sibling of 0x6ce5c0; consumed on registry-B render screens. Meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bff80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
