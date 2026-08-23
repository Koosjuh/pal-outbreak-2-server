# 0x005c2ae0 scenario_subrecord_ptr

| field | value |
|---|---|
| Original address | 0x005c2ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2ae0 |
| Resolved name | scenario_subrecord_ptr |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2f40, FUN_005c3490, FUN_005c3b10
**Callees:** FUN_005c2a40
**Referenced globals:** iRam00368474 (via scenario_record_ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns scenario_record + (a1&0xffff)*0x3c + 0x16c — a 0x3c-stride nested sub-record (per-scenario/per-variant descriptor).

## Notes / uncertainty
Two-level: scenario_record + (subIdx&0xffff)*0x3c + 0x16c. Second index is a decompiler extraout_a1 (calling convention inferred) -> Medium. Nested 0x3c record content unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
