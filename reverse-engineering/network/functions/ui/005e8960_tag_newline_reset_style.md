# 0x005e8960 tag_newline_reset_style

| field | value |
|---|---|
| Original address | 0x005e8960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8960 |
| Resolved name | tag_newline_reset_style |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef380
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: flushes (FUN_005ef040) then runs FUN_005ef380 (line/state finalize).

## Notes / uncertainty
Flush+line-feed (ef040) then FUN_005ef380 which reloads palette (via ec100 xref). Which additional flags ef380 resets not verified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
