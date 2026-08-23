# 0x005bf130 clear_channel_state

| field | value |
|---|---|
| Original address | 0x005bf130 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf130 |
| Resolved name | clear_channel_state |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bfe90, FUN_005c0750, FUN_005c1c80
**Callees:** —
**Referenced globals:** 0x6ce5ce ch0; 0x6ce5cf ch1; 0x6ce5d0 ch2; 0x6ff2b1 scenario/char lock
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ff2b1 lock (memory: 1->3 unlock); 0x6ce5d0

## Behavioral explanation
Clears committed per-channel value (0x6ce5ce/cf/d0) for channel 0/1/2; channel 2 also clears scenario/char lock 0x6ff2b1.

## Notes / uncertainty
committed[ch]=0 (0x6ce5ce/cf/d0); channel 2 also zeroes 0x6ff2b1 unlock gate (re-locks room controls). Confirmed 0x6ff2b1 coupling.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
