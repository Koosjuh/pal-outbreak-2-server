# 0x005c2a90 scenario_field_4c

| field | value |
|---|---|
| Original address | 0x005c2a90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2a90 |
| Resolved name | scenario_field_4c |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c0ff0
**Callees:** FUN_005c2a40
**Referenced globals:** iRam00368474 (via scenario_record_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns scenario_record + 0x4c.

## Notes / uncertainty
Returns scenario_record+0x4c ptr. Field meaning not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2a90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
