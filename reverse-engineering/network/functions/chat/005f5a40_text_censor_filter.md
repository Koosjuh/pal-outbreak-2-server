# 0x005f5a40 text_censor_filter

| field | value |
|---|---|
| Original address | 0x005f5a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5a40 |
| Resolved name | text_censor_filter |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f5c10
**Callees:** —
**Referenced globals:** pcRam0087b268(banned-word pointer list); 0x87b200(word-boundary char pairs)
**Referenced strings:** <banned words @0x87b268>
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Profanity filter: scans a string against a banned-word list and overwrites matched runs with full-width mask glyphs (0x81 0x96).

## Notes / uncertainty
In-place SJIS profanity mask: iterates banned-word char* list 0x87b268, strstr-finds each, validates leading+trailing word boundaries against delimiter-pair table 0x87b200, overwrites bounded runs with full-width mask 0x81 0x96 (wordLen/2 chars). Word/boundary table contents not dumped; first-hit-abandon is a filter quirk.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
