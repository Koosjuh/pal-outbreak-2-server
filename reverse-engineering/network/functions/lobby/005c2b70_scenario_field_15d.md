# 0x005c2b70 scenario_field_15d

| field | value |
|---|---|
| Original address | 0x005c2b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2b70 |
| Resolved name | scenario_field_15d |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c3490
**Callees:** FUN_005c2a40
**Referenced globals:** iRam00368474 (via scenario_record_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns scenario_record + 0x15d.

## Notes / uncertainty
Ptr to scenario_record+0x15d; caller FUN_005c3490 copies 8 bytes -> 8-byte id/descriptor. Meaning not validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
