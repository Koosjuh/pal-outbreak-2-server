# 0x00600de0 field_decode_room_members4

| field | value |
|---|---|
| Original address | 0x00600de0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600de0 |
| Resolved name | field_decode_room_members4 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0d30
**Referenced globals:** 0x6c79ac scratch; 0x6c7c2c/3c/50 member fields (0x10 stride)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate

## Behavioral explanation
Field-sync decoder callback: when active (mode!=6) and full-refresh, clears 0x6c79ac and decodes all 4 room member slots via FUN_005c0d30 into the 0x6c7c2c/3c/50 tables.

## Notes / uncertainty
Field-decode cb: on subtype 0 (and mode!=6) decodes 4 roster records into 0x6c7c2c stride 0x3b0 via FUN_005c0d30. Corrected earlier '0x10 stride' note: decompiler recurrence = i*0x3b0. Field A/B/C semantics delegated to callee.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600de0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
