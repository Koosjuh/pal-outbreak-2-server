# 0x006146e0 draw_text_element

| field | value |
|---|---|
| Original address | 0x006146e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006146e0 |
| Resolved name | draw_text_element |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612b70, FUN_00612ca0, FUN_00612fd0, FUN_006130a0, FUN_00613380, FUN_006134b0, FUN_00613530, FUN_00613600, FUN_00613740, FUN_00613840, FUN_006139c0, FUN_00613aa0, FUN_00613da0, FUN_00613e70, FUN_00613f40, FUN_00613fb0, FUN_006140d0, FUN_00614600
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Primitive that emits one text/label draw element (id,pos) then the string payload; reused by 18 renderers.

## Notes / uncertainty
Core text-draw primitive (18 callers): set pen pos(001af080) then push string(001af190). param_1 raw-X vs element-slot-id ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006146e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
