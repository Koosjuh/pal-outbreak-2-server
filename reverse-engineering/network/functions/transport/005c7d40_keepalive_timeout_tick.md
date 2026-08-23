# 0x005c7d40 keepalive_timeout_tick

| field | value |
|---|---|
| Original address | 0x005c7d40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7d40 |
| Resolved name | keepalive_timeout_tick |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005be330
**Callees:** FUN_005bdf90, FUN_005c7ca0, FUN_005c7e30
**Referenced globals:** 0x6febde (link active); 0x6febdf (awaiting-ack); 0x6febe0 (idle timer); 0x6febe2 (ack timer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6febde; 0x6febdf

## Behavioral explanation
Per-tick keepalive watchdog: counts down idle timer -> send ping; counts down ack timer -> declare link dead (clears 0x6febde, status msg 0xb, FUN_005bdf90(2,0)).

## Notes / uncertainty
Per-frame keepalive SM: idle countdown->ping; ack countdown expiry->link dead (clear 0x6febde, event 0x5c7e30(0xb), session 0x5bdf90(2,0), ret 1). Ties to error-840. Event 0xb / state 2 semantics named by role only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7d40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
