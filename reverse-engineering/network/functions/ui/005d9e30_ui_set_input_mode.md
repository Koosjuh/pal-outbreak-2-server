# 0x005d9e30 ui_set_input_mode

| field | value |
|---|---|
| Original address | 0x005d9e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9e30 |
| Resolved name | ui_set_input_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e67a0
**Callees:** —
**Referenced globals:** iRam00701070+0x34: UI active flag; iRam00701070+0x30: current UI mode; iRam00701070+0x2f: previous UI mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x34; 0x30; 0x2f

## Behavioral explanation
UI state setter: sets active-flag at +0x34 for modes {1,2,4,5}, shifts prev mode +0x30->+0x2f and stores new mode at +0x30.

## Notes / uncertainty
Mode setter: +0x34 active-flag for modes {1,2,4,5}, rotates +0x30->+0x2f. Semantic meaning of individual mode ids not recovered.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
