# 0x005ae510 overlay_countdown_display

| field | value |
|---|---|
| Original address | 0x005ae510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae510 |
| Resolved name | overlay_countdown_display |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae3e0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b9060, FUN_005b9110, FUN_00637180
**Referenced globals:** obj +0x54b4/+0x54b5/+0x54ba/+0x54bd/+0x51a2; 0x638858(fmt str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay state 0 of 54b4: state machine (+0x54b5) that opens a box then runs a countdown 0x54ba, drawing seconds text (val/0x1e) via 5af1e0.

## Notes / uncertainty
Phase-0 of 54b4: countdown popup, inner SM +0x54b5, seconds = timer/0x1e (30Hz), 300-tick(10s) preload on external trigger +0x54bd, fmt str 0x638858. Trigger source (network vs local) not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
