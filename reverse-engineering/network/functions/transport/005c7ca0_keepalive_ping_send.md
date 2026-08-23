# 0x005c7ca0 keepalive_ping_send

| field | value |
|---|---|
| Original address | 0x005c7ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7ca0 |
| Resolved name | keepalive_ping_send |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c7d40
**Callees:** —
**Referenced globals:** 0x6febde (link active); 0x6febdf (awaiting-ack); 0x6febe2 (ack timer); 0x6febac (conn); 0x368492 (timeout const)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6febde; 0x6febdf

## Behavioral explanation
When the link is active, sends a 1-byte keepalive/ping reliably (func_0x001dfda0) and arms the reply-timeout timer.

## Notes / uncertainty
If link active (0x6febde): send 1-byte reliable ping {0x01}, set awaiting-ack 0x6febdf=1, arm ack timer 0x6febe2=*0x368492, cb 0x5c7d20. Mapping to app op0x40 frame not byte-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
