# 0x005b7f70 markup_measure_run_chars

| field | value |
|---|---|
| Original address | 0x005b7f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7f70 |
| Resolved name | markup_measure_run_chars |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005b76f0
**Callees:** FUN_005b7f00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Count displayable characters in a text run up to a byte-length budget, using utf8_char_len to step.

## Notes / uncertainty
Counts chars in a run up to a byte budget via utf8_char_len. Register-artifact decompile (extraout_*); offset/budget (a2/a3) mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7f70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
