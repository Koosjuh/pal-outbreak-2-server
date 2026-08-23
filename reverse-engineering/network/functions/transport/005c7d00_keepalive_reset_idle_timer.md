# 0x005c7d00 keepalive_reset_idle_timer

| field | value |
|---|---|
| Original address | 0x005c7d00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7d00 |
| Resolved name | keepalive_reset_idle_timer |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb4d0, FUN_005bb670, FUN_005bb8e0, FUN_005bb980, FUN_005bba20, FUN_005bc430, FUN_005bc590, FUN_005bc790, FUN_005bf740, FUN_005bf830, FUN_005bfb40, FUN_005bfe90, FUN_005c0060, FUN_005c05c0, FUN_005c0ae0, FUN_005c1220, FUN_005c13e0, FUN_005c19d0, FUN_005c21c0, FUN_005c2460, FUN_005c29c0, FUN_005c3370, FUN_005c39e0, FUN_005c3a40, FUN_005c3cf0, FUN_005c3da0
**Callees:** —
**Referenced globals:** 0x6febdf (awaiting-ack); 0x6febe0 (idle timer); 0x368490 (reload const)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6febdf

## Behavioral explanation
Clears the awaiting-ack flag and reloads the idle timer (0x6febe0) — called on any activity to defer the keepalive.

## Notes / uncertainty
Activity hook (26 handler callers): clear awaiting-ack 0x6febdf, reload idle timer 0x6febe0=*0x368490. Tick period of reload const unmeasured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7d00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
