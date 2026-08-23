# 0x00630910 softkbd_char_allowed_filter

| field | value |
|---|---|
| Original address | 0x00630910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630910 |
| Resolved name | softkbd_char_allowed_filter |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00630750
**Callees:** FUN_00632290, FUN_00637980, FUN_00637ba0, FUN_00637bf0, FUN_00637c40, FUN_00637c70, FUN_00637ca0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x33 filter-flag bits; +0x20 charset/caps bitmask; +0x1d field mode

## Behavioral explanation
Predicate: is a candidate character permitted in the current field, given filter flags (+0x33) and charset caps (+0x20) plus per-field forbidden-char ranges.

## Notes / uncertainty
Admit predicate: +0x33 required-class gates then +0x20 charset/forbidden-char bans (ASCII-only, extended-Latin, symbol list). Exact class each cc_* predicate tests and FUN_00632290 context meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
