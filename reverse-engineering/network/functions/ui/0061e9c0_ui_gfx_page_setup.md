# 0x0061e9c0 ui_gfx_page_setup

| field | value |
|---|---|
| Original address | 0x0061e9c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e9c0 |
| Resolved name | ui_gfx_page_setup |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_0061f8d0, FUN_0061f970, FUN_00620d60, FUN_00621f10, FUN_00623090, FUN_00623600
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
GS/graphics context setup (three extern gfx calls incl. 0x1ad160(6)); menu draw-page init.

## Notes / uncertainty
3 sequential GS externs (init/0x1ad160(6)/flush); pure draw-context setup. Extern semantics + the literal 6 (GS layer id) inferred. File also hosts two thunk copies of redraw_flags_clear_all.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e9c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
