# 0x00619d90 hud_bind_icon_texture

| field | value |
|---|---|
| Original address | 0x00619d90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619d90 |
| Resolved name | hud_bind_icon_texture |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619e00
**Callees:** —
**Referenced globals:** 0x7153f0 texture-handle table; 0x715430 default handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Selects and binds a HUD icon texture handle from table 0x7153f0 (or default 0x715430) and issues the GS texture-set; returns false if no texture.

## Notes / uncertainty
Selects HUD icon texture handle: index==-1 -> default 0x715430 else table 0x7153f0[index]; binds via GS reg 4 if handle!=0; returns bool (bound?). Sole caller FUN_00619e00. Table contents/reg-4 exact meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619d90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
