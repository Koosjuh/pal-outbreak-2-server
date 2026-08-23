# 0x005da370 ui_init_viewport_flags

| field | value |
|---|---|
| Original address | 0x005da370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da370 |
| Resolved name | ui_init_viewport_flags |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7e30
**Callees:** FUN_005da780
**Referenced globals:** iRam00701070+0x18: viewport flag word; iRam00701070+0x5c3; iRam00701070+0x38/0x37: timer/mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x18; 0x38; 0x37

## Behavioral explanation
UI viewport init: stores flag word at +0x18 (forces bit3 when +0x39 set), clears region +0x33b, sets timer 0x1e and mode 1, then computes margins via FUN_005da780.

## Notes / uncertainty
Panel init: latches style flags +0x18 (force bit3 via +0x39), timer 0x1e, mode 1, delegates to ui_compute_margins. border/+0x5c3 semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
