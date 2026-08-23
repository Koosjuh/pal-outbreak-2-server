# 0x00620570 input_hold_counter

| field | value |
|---|---|
| Original address | 0x00620570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00620570 |
| Resolved name | input_hold_counter |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006205c0, FUN_00620d60
**Callees:** —
**Referenced globals:** 0x29a528 pad-state ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Button-hold detector: while pad bit 0x8000 (at *(iRam0029a528+8)) is held, increments *param; returns 1 after >0x1d frames, resets to 0 on release.

## Notes / uncertainty
Long-press detector on pad bit 0x8000 (pad_ctx+8), fires >29 frames. 0x8000 is a pad bit, not the SN@P reliable bit.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00620570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
