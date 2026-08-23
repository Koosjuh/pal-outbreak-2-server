# 0x00613e70 menu_render_list_minus3

| field | value |
|---|---|
| Original address | 0x00613e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613e70 |
| Resolved name | menu_render_list_minus3 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00613c30
**Callees:** FUN_0060f830, FUN_0060f860, FUN_006146e0, FUN_006147a0
**Referenced globals:** iRam0070d1c0 (+0x4e); 0x653ff0; 0x654010
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x4e

## Behavioral explanation
Same table-driven menu renderer as 613da0 but stops 3 rows short (renders all but the last 3 entries).

## Notes / uncertainty
Identical to 613da0 but renders count-3 rows; selected for roster/in-room variant (ctx+0x23==3). Which 3 trailing rows dropped unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
