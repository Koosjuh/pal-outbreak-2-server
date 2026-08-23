# 0x005c4d20 send_op01_to_conn

| field | value |
|---|---|
| Original address | 0x005c4d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4d20 |
| Resolved name | send_op01_to_conn |
| Subsystem | packets |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5ac0, FUN_005ffdc0
**Callees:** FUN_005bf230, FUN_005c5120
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x01
**State vars:** —

## Behavioral explanation
Builds a 0x8000-reliable packet with app-opcode 0x01 + payload and sends it to a specific decoded connID target.

## Notes / uncertainty
Reliable app-op 0x01 send: 4-byte header [00]=0x01, payload at +4, flag 0x8000, ASCII connID decoded to target via FUN_005c5120. func_0x001df380 arg roles and op01 semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
