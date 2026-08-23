# 0x005c4dc0 send_named_ctrl_msg_sub1

| field | value |
|---|---|
| Original address | 0x005c4dc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4dc0 |
| Resolved name | send_named_ctrl_msg_sub1 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bfb40
**Callees:** —
**Referenced globals:** 0x36842c payload-str; 0x6febac net-ctx
**Referenced strings:** str@0x36842c
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sends a small reliable control datagram [0,1,0,<str>] carrying the string at 0x36842c.

## Notes / uncertainty
Builds+sends DATA(who=0x1000) ctrl msg on conn 0x6febac: [0,1,0,strlen,0,0,name@0x36842c], len=strlen+6. Not mapped to a numbered app opcode; reliable-bit handling inside send thunk unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4dc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
