# 0x00612ae0 softkey_layout_build_0x4b

| field | value |
|---|---|
| Original address | 0x00612ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612ae0 |
| Resolved name | softkey_layout_build_0x4b |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614b90
**Callees:** FUN_00614c80
**Referenced globals:** ctx+0x4b (button-set id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4b softkey set

## Behavioral explanation
Small layout builder: switch(ctx+0x4b) enqueues one softkey/button element via FUN_00614c80 (id = 0x4b-1, or special-cased 2/3 for values 4/5).

## Notes / uncertainty
Builds softkey button geometry from ctx+0x4b via FUN_00614c80. Non-linear map: 1..3->id-1, 4->2, 5->3, 0/>=6->none. Trailing (0,0) args unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
