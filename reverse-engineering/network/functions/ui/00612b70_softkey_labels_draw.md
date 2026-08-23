# 0x00612b70 softkey_labels_draw

| field | value |
|---|---|
| Original address | 0x00612b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612b70 |
| Resolved name | softkey_labels_draw |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_006146e0
**Referenced globals:** 0x653f30 (per-lang softkey strings); bRam0034359d (language); ctx+0x4b (button-set id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4b softkey set

## Behavioral explanation
Draws softkey label text: switch(ctx+0x4b) picks 1-5 label strings from per-language table 0x653f30 and blits each at fixed x via FUN_006146e0(x,400,str).

## Notes / uncertainty
Draws softkey captions from per-lang table 0x653f30, switch(ctx+0x4b), fixed x at y=400. Set 4 uses label index [3] (skips [2]), mirroring geometry aliasing. Table text not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
