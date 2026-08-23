# 0x005bfc40 get_short_0x6ce5c0

| field | value |
|---|---|
| Original address | 0x005bfc40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfc40 |
| Resolved name | get_short_0x6ce5c0 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90, FUN_005f7b30
**Callees:** —
**Referenced globals:** 0x6ce5c0 roster field (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 16-bit global field 0x6ce5c0 into out-ptr.

## Notes / uncertainty
Singleton u16 scalar (not indexed); likely record-A header word paired with 0x6ce5c2. Meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfc40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
