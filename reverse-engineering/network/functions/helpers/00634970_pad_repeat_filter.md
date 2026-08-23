# 0x00634970 pad_repeat_filter

| field | value |
|---|---|
| Original address | 0x00634970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634970 |
| Resolved name | pad_repeat_filter |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0, FUN_00634ab0, FUN_006352e0, FUN_006353e0, FUN_00635cb0, FUN_00635f80, FUN_00636f90
**Callees:** —
**Referenced globals:** 0x715da8+0x1a (held mask); 0x715da8+0x1c (repeat counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x1a; 0x715da8+0x1c

## Behavioral explanation
Auto-repeat debounce over pad button mask (0xedf d-pad/face bits): passes edge presses immediately, then repeats every ~2 frames after a 10-frame initial delay.

## Notes / uncertainty
Auto-repeat debounce over 0xEDF button set (NOT an opcode): edge fires once, 10-frame delay, 2-frame repeat. Bit->physical-button mapping not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
