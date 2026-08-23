# 0x00631ff0 softkbd_ime_commit_composition

| field | value |
|---|---|
| Original address | 0x00631ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631ff0 |
| Resolved name | softkbd_ime_commit_composition |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630750, FUN_006312c0, FUN_00631670, FUN_00631e40, FUN_00633430, FUN_00634ab0, FUN_006353e0, FUN_006355a0, FUN_00635bb0, FUN_00635ed0, FUN_006378b0
**Callees:** FUN_006320f0, FUN_00634880, FUN_00637ed0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x260 IME buffer; +0x45c backup buffer; +0x4c main buffer; +0x2a/0x2c cursors; +0x2f IME state; +0x30 mode; +0x26 active; +0x28 dirty; +0x3a max width

## Behavioral explanation
Commits the IME composition buffer (+0x260) into the main text buffer (+0x4c): backs it up to +0x45c, inserts at cursor, clears composition (memset 0xfa), updates cursors.

## Notes / uncertainty
Central IME->main splice: backs up +0x260 to +0x45c, finalizes state 3 (FUN_00634880), insert_string_fit_width, memset 0xfa, advance caret. Fall-through for states 0/2 slightly ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
