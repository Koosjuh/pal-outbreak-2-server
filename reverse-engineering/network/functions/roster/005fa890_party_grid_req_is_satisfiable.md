# 0x005fa890 party_grid_req_is_satisfiable

| field | value |
|---|---|
| Original address | 0x005fa890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa890 |
| Resolved name | party_grid_req_is_satisfiable |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa990
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans the 4-slot grid for the first occupied slot whose type/id matches the probe; returns 1 on hit.

## Notes / uncertainty
Single-row form of 005fa700 (same 0x3b0 grid, 0x309c/3188/318a fields, 6/0x5b rule); returns 1 if one requirement is satisfiable. Same inferred dual-form semantics.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
