# 0x005b7320 markup_tokenize_line

| field | value |
|---|---|
| Original address | 0x005b7320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7320 |
| Resolved name | markup_tokenize_line |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005b7cd0, FUN_005b7de0
**Callees:** FUN_005b7270, FUN_005b7f00
**Referenced globals:** 0x6ca600 (run array, 600 bytes); sRam006ca884 (char count); cRam006ca881/882 (parser state); pcRam006ca87c (cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ca881; cRam006ca882; sRam006ca884

## Behavioral explanation
Tokenize one line of markup text into the run array at 0x6ca600 (up to 0x1e runs), handling multibyte chars (FUN_005b7f00), '\' escapes and '<' tag groups; sets parser end/error state.

## Notes / uncertainty
Splits a line into 12-byte runs at 0x6ca600; handles multibyte/escape/tag-break. Run-split bookkeeping (cur/w/run_idx) and 0x1e-vs-0x1d cap partly inferred from goto-flattened decompile.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
