# 0x005d60a0 chat_text_match_compose

| field | value |
|---|---|
| Original address | 0x005d60a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d60a0 |
| Resolved name | chat_text_match_compose |
| Subsystem | chat |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c9c50
**Callees:** FUN_005d59f0, FUN_005d5cc0, FUN_005d6560, FUN_005de330
**Referenced globals:** 0x701080+0x21e entered text; 0x701080+0x2421 out buf; 0x701070+0x30 sub-state; 0x701068+0x4db5c dest
**Referenced strings:** str@0x642fd0; str@0x642fe0; str@0x642ff0; str@0x643000; str@0x643010; str@0x643020; str@0x643030; str@0x643040; str@0x643050; str@0x643060; str@0x643070; str@0x643080; str@0x643090; str@0x6430a0; str@0x6430b0; str@0x6430c0
**Referenced opcodes:** —
**State vars:** 0x701070+0x30

## Behavioral explanation
Matches the user-entered text (0x701080+0x21e) against a table of literal strings to pick an index, composes a formatted record via 6560, then sets label and resets.

## Notes / uncertainty
Compose validator: requires entered text (701080+0x21e) >=8 chars; in sub-state 4/5 classifies text against 16-string keyword table (0x642fd0..0x6430b0) -> category 0..6, builds localized header via FUN_005de330(6,cat), composes body via 005d6560, returns 1; states 1/2 ->0; else ->-1. Keyword strings unresolved; category groupings (many->0) suggest synonyms; state 4/5 vs 1/2 = edit/confirm inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d60a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
