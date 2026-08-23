# 0x00632d20 censor_bad_words

| field | value |
|---|---|
| Original address | 0x00632d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632d20 |
| Resolved name | censor_bad_words |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00632ce0
**Callees:** FUN_00633000, FUN_006331a0, FUN_006332a0
**Referenced globals:** 0x68b6e0 (bad-word list, s_AFTER_0068b6e0); 0x68ef90 (char-class table)
**Referenced strings:** AFTER (0068b6e0 wordlist region)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Word-filter: normalizes entered text, scans a packed wordlist, and overwrites matched substrings with '*' respecting word boundaries.

## Notes / uncertainty
Core profanity censor: normalize -> per-position wordlist match (leet-aware: 1/!->L, (/< skip at start) -> boundary check -> star span. Final 'advance to next word' do/while is a faithful but tangled transcription (Medium). param_2 pass flag has no visible body effect.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
