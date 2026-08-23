# 0x005baf20 record_get_byte3

| field | value |
|---|---|
| Original address | 0x005baf20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baf20 |
| Resolved name | record_get_byte3 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe300
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field accessor: returns byte at record+3 in table base(0), stride 0x1e4.

## Notes / uncertainty
Reads byte+3 (leading status byte, diff-compared) of current 0x1e4 record. Semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baf20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
