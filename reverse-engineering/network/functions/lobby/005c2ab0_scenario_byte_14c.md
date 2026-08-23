# 0x005c2ab0 scenario_byte_14c

| field | value |
|---|---|
| Original address | 0x005c2ab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2ab0 |
| Resolved name | scenario_byte_14c |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c1220
**Callees:** FUN_005c2a40
**Referenced globals:** iRam00368474 (via scenario_record_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the byte at scenario_record + 0x14c.

## Notes / uncertainty
Value getter: *(u8*)(scenario_record+0x14c). Scalar attribute; count/flag/id ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
