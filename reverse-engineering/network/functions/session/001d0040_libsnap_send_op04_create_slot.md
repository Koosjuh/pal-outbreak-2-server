# 0x001d0040 libsnap_send_op04_create_slot

| field | value |
|---|---|
| Original address | 0x001d0040 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0040 |
| Resolved name | libsnap_send_op04_create_slot |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00106b60, FUN_00109728, FUN_001a1750, FUN_001a7b70, FUN_001ab460, FUN_001cb360, FUN_001cbc20, FUN_001cce80
**Referenced globals:** 0x3f49a8/0x3f41a0 send buffers; 0x3ce350 parsed record; 0x3ce308/0x3ce30c list head; cRam00343577 offline-mode; uRam0034357a session id
**Referenced strings:** 0x24cc50 template; 0x24cc60 template; 0x24cc80 template
**Referenced opcodes:** 0x04
**State vars:** cRam00343577; uRam0034357a

## Behavioral explanation
Channel 0x2000, alloc tag 4, reliable send FUN_001cce80 (offline FUN_001a1750) with tmpl 0x24cc50/0x24cc60/0x24cc80 (uRam0034357a); parses the reply into 0x3ce350 and sets list ptr 0x3ce30c.

## Notes / uncertainty
Create-room op04 emitter (blocker-relevant): channel 0x2000, 9 attr presets, alloc tag 4, reliable send 0x3f41a0, then FUN_001cb360 parses reply -> only on non-zero copies record to 0x3ce350 and publishes list ptr 0x3ce30c=0x3ce750 (the commit signal). Uncertainty: 0x24cc50/60/80 template field layouts; whether cb blocks for reply.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0040.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
