# 0x005ba8d0 clock_widget_cb

| field | value |
|---|---|
| Original address | 0x005ba8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba8d0 |
| Resolved name | clock_widget_cb |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005ba800
**Referenced globals:** 0x006c4fb0 uRam=elapsed-time counter; 0x639e18 fmt string
**Referenced strings:** 0x639e18
**Referenced opcodes:** —
**State vars:** uRam006c4fb0

## Behavioral explanation
Clock widget callback: formats the global elapsed timer uRam006c4fb0 via FUN_005ba800 and draws it as text with fmt 0x639e18.

## Notes / uncertainty
Per-frame clock HUD: format_frames_to_hms(g frame counter 0x6c4fb0)->sprintf(fmt 0x639e18)->draw at (48,404). Non-net. Exact fmt glyph not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
