# 0x005c5e30 send_op07_charstats

| field | value |
|---|---|
| Original address | 0x005c5e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5e30 |
| Resolved name | send_op07_charstats |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** —

## Behavioral explanation
Builds and sends the reliable app-opcode 0x07 leave/notify packet with a 0x36-byte payload to the target.

## Notes / uncertainty
Renamed from send_op07_leave: SM body shows this carries a 0x36-byte CHARSTATS chunk (0x28/0x32 slices of the 0xf0 charstats block at 0x700734), not a leave. op10-relay, inner op 0x07. Could still be transport 'leave' opcode reused as detail carrier.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
