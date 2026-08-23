# 0x005d7e00 txn_begin_enter

| field | value |
|---|---|
| Original address | 0x005d7e00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7e00 |
| Resolved name | txn_begin_enter |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d80c0
**Callees:** FUN_005d7410, FUN_005d7760, FUN_005d7cf0, FUN_005dedc0, FUN_005df340
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** record+0x104 state; record+0x124 error

## Behavioral explanation
Processes a state-4 subtype-1 txn record: copies its key, looks it up (FUN_005df340), runs session_enter_dispatch; on accept (node state 3) allocates a send object (func_0x01212970) with an 0x8000 buffer and fills its descriptor, or on state 2 marks the record done (state 5).

## Notes / uncertainty
Pumps a state-4 subtype-1 txn: build key, validate vs session name, call session_enter_dispatch; node state 3 -> alloc send obj + build enter packet (reliable iff subtype 0x06/0x02, 0x8000 buf), state 2 -> done(5), else err(6, class 2/8). FUN_005d7cf0 packet layout not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
