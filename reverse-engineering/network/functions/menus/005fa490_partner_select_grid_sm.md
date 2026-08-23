# 0x005fa490 partner_select_grid_sm

| field | value |
|---|---|
| Original address | 0x005fa490 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa490 |
| Resolved name | partner_select_grid_sm |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005fa700, FUN_005fa990, FUN_005fb670, FUN_005fba80, FUN_005fc850
**Referenced globals:** +0x909 grid flag; +0x448/+0x449 flags; +0x97c result
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state; +0x11 toggle

## Behavioral explanation
Selection-grid screen SM (character/partner pick): reads D-pad/buttons, moves cursor over the 4-slot grid, plays SFX, guards on connection.

## Notes / uncertainty
Already fully reconstructed. 3-phase grid SM on +0x10. Button masks (0x10/0x20/0x200/0x400/0x800) and partner-vs-character role inferred; nested +0x909 axis branch least certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa490.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
