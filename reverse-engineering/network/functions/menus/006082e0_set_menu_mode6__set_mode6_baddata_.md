# 0x006082e0 set_menu_mode6 (set_mode6_baddata)

| field | value |
|---|---|
| Original address | 0x006082e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006082e0 |
| Resolved name | set_menu_mode6 (set_mode6_baddata) |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_00606cb0
**Callees:** —
**Referenced globals:** 0x006c4faa mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa

## Behavioral explanation
Sets mode 6c4faa=6 then hits a bad-instruction truncation.

## Notes / uncertainty
Only the write g_menu_mode(0x006c4faa)=6 is recoverable; body truncated by bad-instruction (halt_baddata). Meaning of mode 6 inferred from sibling selectors. Not on net path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006082e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
