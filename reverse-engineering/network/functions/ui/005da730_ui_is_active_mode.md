# 0x005da730 ui_is_active_mode

| field | value |
|---|---|
| Original address | 0x005da730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da730 |
| Resolved name | ui_is_active_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8ea0, FUN_005d95f0, FUN_005d96a0, FUN_005d9790
**Callees:** —
**Referenced globals:** iRam00701070+0x30: current UI mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x30

## Behavioral explanation
UI predicate: returns 1 if current input mode (+0x30) is in {1,2,4,5} (drag/active) and for mode 5, else 0.

## Notes / uncertainty
Renamed from ui_is_drag_mode: predicate returns 1 for mode in {1,2,4,5}; covers more than drag. Same partition as ui_set_input_mode.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
