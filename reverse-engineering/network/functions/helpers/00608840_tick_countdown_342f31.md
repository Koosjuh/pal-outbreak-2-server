# 0x00608840 tick_countdown_342f31

| field | value |
|---|---|
| Original address | 0x00608840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608840 |
| Resolved name | tick_countdown_342f31 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae310, FUN_005f4480, FUN_005f6d20, FUN_006076c0, FUN_00608300
**Callees:** —
**Referenced globals:** 0x00342f30 countdown-hi; 0x00342f31 countdown; 0x006c547c seed
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c547c

## Behavioral explanation
If seed 6c547c set, latches 342f30/31 from 6c547c/d then decrements the 342f31 countdown.

## Notes / uncertainty
Edge-latched byte countdown armed by 0x6c547c, reload 0x6c547d, decrements 0x342f31. What it gates unknown; unguarded underflow. Sibling thunk_FUN_006235f0 noted separately.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
