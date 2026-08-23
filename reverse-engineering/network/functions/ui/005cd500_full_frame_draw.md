# 0x005cd500 full_frame_draw

| field | value |
|---|---|
| Original address | 0x005cd500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd500 |
| Resolved name | full_frame_draw |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dff90, FUN_005e0320
**Referenced globals:** 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+2

## Behavioral explanation
Draws the complete set of overlay sprite tables (layers 0..8) unconditionally, then sets step to 2.

## Notes / uncertainty
Step-1: emits layers 0,1,2(x3),3,4,6,8 via FUN_005dff90(layer)/FUN_005e0320(table); scr+2=2. Table blob contents not disassembled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
