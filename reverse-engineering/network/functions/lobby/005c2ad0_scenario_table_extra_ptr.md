# 0x005c2ad0 scenario_table_extra_ptr

| field | value |
|---|---|
| Original address | 0x005c2ad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2ad0 |
| Resolved name | scenario_table_extra_ptr |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c2f40, FUN_005c3b10
**Callees:** —
**Referenced globals:** iRam00368474 + 0x12fc (fixed sub-table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns iRam00368474 + 0x12fc — a fixed (non-indexed) sub-table within the scenario/area data block.

## Notes / uncertainty
Fixed (non-indexed) sub-block iRam00368474+0x12fc, shared across scenarios (does NOT call record_ptr). 'trails 10 records' arithmetic inferred; block layout unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2ad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
