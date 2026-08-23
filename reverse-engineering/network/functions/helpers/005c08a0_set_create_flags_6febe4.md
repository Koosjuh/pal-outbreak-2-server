# 0x005c08a0 set_create_flags_6febe4

| field | value |
|---|---|
| Original address | 0x005c08a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c08a0 |
| Resolved name | set_create_flags_6febe4 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5d20, FUN_005f99c0, FUN_0062de90
**Callees:** —
**Referenced globals:** 0x6febe4 (stored value)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6febe4

## Behavioral explanation
Stores param_1 into global 0x6febe4.

## Notes / uncertainty
Setter for create-request flags/selector word 0x6febe4 (read by create pump: selector OR + <<1 send length). Bitfield layout unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c08a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
