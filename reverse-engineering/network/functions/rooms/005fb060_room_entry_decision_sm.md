# 0x005fb060 room_entry_decision_sm

| field | value |
|---|---|
| Original address | 0x005fb060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb060 |
| Resolved name | room_entry_decision_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005adc80, FUN_005b14b0, FUN_005b8cf0, FUN_005b9110, FUN_005fb270, FUN_005fb670
**Referenced globals:** 0x6c0774 room flags (bit16/17); cRam00343571 mode; +0x996 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10/+0x11 sub-state; cRam00343571

## Behavioral explanation
Post-select routing SM: reads room-slot flags 0x10000/0x20000 (@0x6c0774) + mode cRam00343571 to choose create vs join vs locked path.

## Notes / uncertainty
Routing SM: reads room flags 0x6c0774 bits 0x10000/0x20000 x mode cRam00343571 (0/1/2) to pick direct/confirm/password/create path; delegates dialog to FUN_005fb270. Exact real-world meaning of bit16 vs bit17 and each mode value needs a trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
