# 0x0062d3d0 open_name_kbd_step

| field | value |
|---|---|
| Original address | 0x0062d3d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d3d0 |
| Resolved name | open_name_kbd_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d380
**Callees:** FUN_006345e0, FUN_006371d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+1 menu-state; param+2 flag

## Behavioral explanation
Menu confirm handler: bumps struct+1 state byte, plays a cue (FUN_006371d0 with 0x42980000 float), advances cursor selection at param+0x11.

## Notes / uncertainty
Renamed from lobby_menu_select_advance. OPEN step of name-entry submachine: opens on-screen keyboard (open_name_entry) for text at param_3+0x11, maxlen 0xf. Whether field is room title/password/search name unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d3d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
