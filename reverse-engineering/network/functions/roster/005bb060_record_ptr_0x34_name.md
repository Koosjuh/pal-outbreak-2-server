# 0x005bb060 record_ptr_0x34_name

| field | value |
|---|---|
| Original address | 0x005bb060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb060 |
| Resolved name | record_ptr_0x34_name |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005affb0, FUN_005ba5b0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns a pointer to record+0x34 (a string field, strcmp'd in the diff; used as room/player name by FUN_005ba5b0).

## Notes / uncertainty
Returns POINTER to +0x34 field, proven a C string by strcmp in record_changed_diff. The record's display name/title.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
