# 0x0060f1b0 room_name_is_reserved_check

| field | value |
|---|---|
| Original address | 0x0060f1b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f1b0 |
| Resolved name | room_name_is_reserved_check |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** —
**Referenced globals:** 0x64b7b0/0x64b7c0 (reserved-key literals)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
strcmp's record+8 vs 0x64b7b0 and record+0xc vs 0x64b7c0; returns 1 only if BOTH differ (i.e. not a reserved/sentinel room), else 0.

## Notes / uncertainty
CORRECTED inverted logic: strcmp==0 means EQUAL, so returns 1 when BOTH keys MATCH the reserved literals (=is reserved), not 'both differ' as the old record said. Literal text @0x64b7b0/c0 not fetched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f1b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
