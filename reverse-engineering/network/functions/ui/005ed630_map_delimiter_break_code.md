# 0x005ed630 map_delimiter_break_code

| field | value |
|---|---|
| Original address | 0x005ed630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed630 |
| Resolved name | map_delimiter_break_code |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0, FUN_005ee220, FUN_005ee470
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps a leading control/punct char ('/','.','-',',','(', \t etc.) to a small tab/indent-type code and NUL-terminates it.

## Notes / uncertainty
Maps leading delimiter (/ . - , ( \n \t \v \b) to break/indent code (/->0x11 etc), NUL-terminates the byte on every path. Downstream meaning of codes inferred. Renamed from map_control_char.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
