# 0x005df600 str_tolower_inplace

| field | value |
|---|---|
| Original address | 0x005df600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df600 |
| Resolved name | str_tolower_inplace |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005df640
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Lowercases an ASCII string in place (A-Z -> a-z).

## Notes / uncertainty
Rewrote to full reconstruction. In-place ASCII A-Z->a-z (+0x20); signed-char guard excludes 0x80+ bytes. Used by the scheme-blocklist matcher to case-fold before prefix compare.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
