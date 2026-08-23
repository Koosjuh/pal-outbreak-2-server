# 0x00613f40 menu_render_entry

| field | value |
|---|---|
| Original address | 0x00613f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613f40 |
| Resolved name | menu_render_entry |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00613c30
**Callees:** FUN_0060f830, FUN_006146e0, FUN_006147a0
**Referenced globals:** iRam0070d1c0 (+0x4e); 0x653ff0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x4e

## Behavioral explanation
Renders one indexed menu-table row (index passed via register) as a single text element.

## Notes / uncertainty
Renders single row index=param_1 (row = base+index*8). index->a2*8 offset is a decompiler-register (extraout_a2_lo) inference, not directly visible.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
