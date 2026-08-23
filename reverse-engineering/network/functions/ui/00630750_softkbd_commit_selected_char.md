# 0x00630750 softkbd_commit_selected_char

| field | value |
|---|---|
| Original address | 0x00630750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630750 |
| Resolved name | softkbd_commit_selected_char |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006352e0
**Callees:** FUN_00630910, FUN_00631ff0, FUN_006320f0, FUN_00635500, FUN_00637980, FUN_00637d10
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1d mode; +0x33 filter flags; +0x2a main cursor; +0x2c IME cursor; +0x260 IME buffer; +0x4c main buffer; +0x3a max width; +0x248 result code

## Behavioral explanation
Commits the character for the selected/typed key: classifies it, applies special-key rules (space/0x20 etc.), validates via the char filter, then inserts into the active text buffer.

## Notes / uncertainty
Classifies char then inserts into main(+0x4c) or IME(+0x260) buffer via 0x6320f0; clears +0x28, sets redraw +0x248=1. Class codes (1/2) from 0x1af420 and category sign from 0x635500 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
