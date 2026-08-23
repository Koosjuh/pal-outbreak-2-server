# 0x005c4e60 send_named_ctrl_msg_sub2

| field | value |
|---|---|
| Original address | 0x005c4e60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4e60 |
| Resolved name | send_named_ctrl_msg_sub2 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005be330
**Callees:** —
**Referenced globals:** 0x36842c payload-str; 0x6febac net-ctx
**Referenced strings:** str@0x36842c
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sends a small reliable control datagram [0,2,0,<str>] carrying the string at 0x36842c.

## Notes / uncertainty
Sub-selector=2 twin of 0x5c4dc0 (only byte[1] differs). sub1/sub2 = two phases/variants of same named handshake (callers bfb40 vs be330).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4e60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
