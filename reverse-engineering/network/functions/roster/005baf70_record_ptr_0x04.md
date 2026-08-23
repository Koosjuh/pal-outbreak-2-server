# 0x005baf70 record_ptr_0x04

| field | value |
|---|---|
| Original address | 0x005baf70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baf70 |
| Resolved name | record_ptr_0x04 |
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
Returns a pointer to record+4 (a 0x10-byte field, likely id/name) in table base(0), stride 0x1e4.

## Notes / uncertainty
Returns POINTER to +0x04 field (16-byte identity blob, memcmp'd 0x10 in diff). Aliases live table memory.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baf70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
