# 0x00614600 menu_render_list_alt

| field | value |
|---|---|
| Original address | 0x00614600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614600 |
| Resolved name | menu_render_list_alt |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_0060f830, FUN_0060f860, FUN_006146e0, FUN_006147a0
**Referenced globals:** iRam0070d1c0 (+0x4f,+0x50); 0x654030; 0x654050
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x4f; iRam0070d1c0+0x50

## Behavioral explanation
Table-driven menu renderer using a second layout set (0x654030/0x654050) keyed by iRam+0x4f + iRam+0x50.

## Notes / uncertainty
Same as 613da0 but alt tables 0x654030/0x654050 keyed by ctx+0x4f+ctx+0x50 (screen selector, not msg id); called from frame renderer 0x60f910. Meaning of 0x4f+0x50 sum inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
