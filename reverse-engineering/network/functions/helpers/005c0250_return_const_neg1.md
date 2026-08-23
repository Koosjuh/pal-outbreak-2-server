# 0x005c0250 return_const_neg1

| field | value |
|---|---|
| Original address | 0x005c0250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0250 |
| Resolved name | return_const_neg1 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe8d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stub returning 0xffffffff (-1), used as a fixed no-op/'invalid' provider.

## Notes / uncertainty
Returns -1 sentinel (inert dispatch branch in FUN_005fe8d0 room-enter table). Behavior certain; which slot it stands in for unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
