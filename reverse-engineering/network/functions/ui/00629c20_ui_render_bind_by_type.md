# 0x00629c20 ui_render_bind_by_type

| field | value |
|---|---|
| Original address | 0x00629c20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629c20 |
| Resolved name | ui_render_bind_by_type |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ba4c0, FUN_0062fdc0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Selects a render/string set (FUN_0062fdc0 with type +3) and binds it via FUN_005ba4c0 for a widget record.

## Notes / uncertainty
Binds render/string set (subtype+3) to active widget. Content of FUN_0062fdc0 table (font vs string-set) not fully pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629c20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
