# 0x005bc240 inroom_evt0a_send_op0b_reply

| field | value |
|---|---|
| Original address | 0x005bc240 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc240 |
| Resolved name | inroom_evt0a_send_op0b_reply |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005c5f70
**Referenced globals:** 0x6febec (reply value)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-event 10: sends a small reply carrying a stored value (0x6febec) back to the room via FUN_005c5f70.

## Notes / uncertainty
Dispatcher case 0x0a: sends reliable (0x8000) SN@P app msg body[0]=0x0b carrying u32 @0x6febec (via FUN_005c5f70) on session 0x6febac to peer. Echoed value meaning + op0b wire role unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc240.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
