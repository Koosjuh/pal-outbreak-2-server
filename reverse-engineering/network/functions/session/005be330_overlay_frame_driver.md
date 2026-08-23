# 0x005be330 overlay_frame_driver

| field | value |
|---|---|
| Original address | 0x005be330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be330 |
| Resolved name | overlay_frame_driver |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005bce20, FUN_005bdf90, FUN_005be270, FUN_005bf1e0, FUN_005c4e60, FUN_005c4f00, FUN_005c6150, FUN_005c7d40, FUN_005c7e30
**Referenced globals:** 0x6ca950 net-active guard; 0x6ff2b1 scenario/cast lock; 0x6ff2b0 room-ready flag; 0x6ff2b2 stage flag; 0x6febec/f4 countdown timers; 0x6cfa2c room member-count table (0x144 stride); 0x700682 counter; 0x7006a4/a6 capacity thresholds
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ff2b1 scenario/cast lock (1->3); 0x6ff2b0 room-ready; 0x6ff2b2 stage; 0x6ca950 net-active

## Behavioral explanation
Master per-frame overlay tick: guarded by iRam006ca950, drives session poll (FUN_005c7d40/FUN_005bf1e0), runs scenario/cast-lock countdowns that flip cRam006ff2b1 to 3 and cRam006ff2b2 stages, capacity-checks room member count at 0x6cfa2c, and pumps task slots via FUN_005be270.

## Notes / uncertainty
G12-HIGH-VALUE. Master per-frame tick. Flips 0x6ff2b1 unlock_gate 1->3 ONLY after FUN_005c4f00 ready AND room member-count (0x6cfa2c[room], stride 0x144, min 2) meets threshold; else screen7 'not enough players'. Host countdown (0x6ff2b0!=0) vs non-host stage machine (0x6ff2b2). FUN_005c4f00 precondition undecompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
