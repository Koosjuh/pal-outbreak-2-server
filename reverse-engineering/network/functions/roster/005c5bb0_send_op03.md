# 0x005c5bb0 send_op03

| field | value |
|---|---|
| Original address | 0x005c5bb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5bb0 |
| Resolved name | send_op03 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x03
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x03 packet to the target conn (roster-sync step).

## Notes / uncertainty
Host->member relay of inner app-op 0x03, body-less, via op10 multicast (func_0x001df380, who=0x8000, count=1, recipient=param_1). Emitted per member in roster-sync SM init phase. Empty-body-on-wire unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
