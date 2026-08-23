# 0x006331a0 is_word_boundary_or_match

| field | value |
|---|---|
| Original address | 0x006331a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006331a0 |
| Resolved name | is_word_boundary_or_match |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00632d20
**Callees:** FUN_00633210
**Referenced globals:** 0x68ef90 (char-class table); 0x68b6e0 (wordlist)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns true if the char is a non-word char (boundary) or begins a wordlist match, using the char-class table and FUN_00633210.

## Notes / uncertainty
Post-match tail test: true if end-of-string, separator (class table 0x68ef90==0), or tail itself starts a wordlist word (wordlist_contains). Handles compounds.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006331a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
