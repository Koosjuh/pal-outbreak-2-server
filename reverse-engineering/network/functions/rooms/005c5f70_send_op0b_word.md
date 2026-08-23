# 0x005c5f70 send_op0b_word

| field | value |
|---|---|
| Original address | 0x005c5f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5f70 |
| Resolved name | send_op0b_word |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bc240
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x0b
**State vars:** —

## Behavioral explanation
Builds and sends a reliable app-opcode 0x0b packet with a 4-byte payload to the target.

## Notes / uncertainty
Reliable app op0b + one 4-byte arg (len 8). Renamed from send_op0b. op0b not in wire list; 4-byte word role (room/slot id) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5f70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
