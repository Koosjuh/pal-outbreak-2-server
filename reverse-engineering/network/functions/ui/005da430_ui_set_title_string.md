# 0x005da430 ui_set_title_string

| field | value |
|---|---|
| Original address | 0x005da430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da430 |
| Resolved name | ui_set_title_string |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7070
**Callees:** —
**Referenced globals:** iRam00701070+0x55d: title string; 0x870870: global title buffer; iRam00701070+0x31: UI flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x31

## Behavioral explanation
UI: copies a title/name string into viewport state +0x55d and, if non-empty, clears flag +0x31 and mirrors the string into global buffer 0x870870.

## Notes / uncertainty
Copies title to +0x55d; if non-empty mirrors into global 16-byte buffer 0x870870 and clears +0x31. Consumer of 0x870870 not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
