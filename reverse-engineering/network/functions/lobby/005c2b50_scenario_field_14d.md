# 0x005c2b50 scenario_field_14d

| field | value |
|---|---|
| Original address | 0x005c2b50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2b50 |
| Resolved name | scenario_field_14d |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c3190
**Callees:** FUN_005c2a40
**Referenced globals:** iRam00368474 (via scenario_record_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns scenario_record + 0x14d.

## Notes / uncertainty
Ptr to scenario_record+0x14d; caller FUN_005c3190 copies 0xf bytes -> ~15-byte label/name field. Encoding not validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2b50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
