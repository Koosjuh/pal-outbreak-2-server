# 0x005bf2e0 registry_b_find_by_key

| field | value |
|---|---|
| Original address | 0x005bf2e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf2e0 |
| Resolved name | registry_b_find_by_key |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c0060
**Callees:** —
**Referenced globals:** 0x6fee8c registry B (30x0x24)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Linear-searches registry B (30 entries, stride 0x24 @0x6fee8c) for entry whose key word == param; returns index or -1.

## Notes / uncertainty
Same as A for registry B (30 slots @0x6fee8c); 30-count == room-list page size. Room-handle -> slot resolver. Which column is ENTER-target vs list-key unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf2e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
