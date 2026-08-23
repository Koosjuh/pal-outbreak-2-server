# 0x005ba2e0 count_widget_cb

| field | value |
|---|---|
| Original address | 0x005ba2e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba2e0 |
| Resolved name | count_widget_cb |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b7cd0, FUN_005b9120, FUN_00618c20
**Referenced globals:** 0x006ca04d uRam=flag set on subtype 1; 0x006c9d33 string buffer
**Referenced strings:** 0x6c9d33
**Referenced opcodes:** —
**State vars:** uRam006ca04d

## Behavioral explanation
Display callback that draws a positioned label/value: subtype 1 centers a string and places it via FUN_005b7cd0 at fixed coords; otherwise picks one of two y-rows; consumes the +0x10 data ptr.

## Notes / uncertainty
Count/label callback; subtype 1 centers title + sets uRam006ca04d, else two body rows via FUN_005b7cd0. Float-coord decode and uRam006ca04d consumer not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba2e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
