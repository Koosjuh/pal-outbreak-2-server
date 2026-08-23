# 0x001d06d0 decode_member_grid_20row

| field | value |
|---|---|
| Original address | 0x001d06d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d06d0 |
| Resolved name | decode_member_grid_20row |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d09c0, FUN_001d0a50
**Callees:** FUN_00188a30, FUN_00188ad0
**Referenced globals:** iRam003435bc work base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Decodes a member record set into a 20-row x 100-col display grid at param_2, with per-cell present markers (offset 0xfa4) and a normal/mirrored layout (param_5); interns name ids like FUN_001d0510.

## Notes / uncertainty
20-row wrapped grid with variable columns, present-marker table at +0xfa4 (bit 0x8000 normal / 2000-base mirror layout via param_5), summary count at +0x1f44/+0x1f46. Same interning as 8row. Mirror-layout consumer screen unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d06d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
