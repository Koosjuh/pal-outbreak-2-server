# 0x005cd730 cursor_mode_dispatch

| field | value |
|---|---|
| Original address | 0x005cd730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd730 |
| Resolved name | cursor_mode_dispatch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8870
**Callees:** —
**Referenced globals:** PTR_FUN_00642d40 cursor-mode table; 0x701078 cursor mode byte
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701078

## Behavioral explanation
Indirect-call dispatcher over jump table PTR_FUN_00642d40 indexed by the cursor-mode byte at 0x701078.

## Notes / uncertainty
Second SM: indirect jump over 0x642d40 cursor-mode table indexed by cur[0]. Mode-handler list not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
