# 0x005ae750 overlay_reset_54b4

| field | value |
|---|---|
| Original address | 0x005ae750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae750 |
| Resolved name | overlay_reset_54b4 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae3e0
**Callees:** —
**Referenced globals:** obj +0x51a2/+0x54b4/+0x54b5/+0x54b8/+0x54bc
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Resets the overlay/dialog state fields (+0x51a2,+0x54b4,+0x54b5,+0x54b8,+0x54bc) to 0.

## Notes / uncertainty
Phase-2 of 54b4: zeroes overlay state {+0x51a2,+0x54b4,+0x54b5,+0x54b8,+0x54bc}. Role of +0x54b8 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
