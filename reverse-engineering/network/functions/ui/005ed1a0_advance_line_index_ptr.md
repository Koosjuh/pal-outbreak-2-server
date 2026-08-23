# 0x005ed1a0 advance_line_index_ptr

| field | value |
|---|---|
| Original address | 0x005ed1a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed1a0 |
| Resolved name | advance_line_index_ptr |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed460, FUN_005ee840, FUN_005eed40, FUN_005f3230, FUN_005f3310, FUN_005f39d0
**Callees:** —
**Referenced globals:** iRam007012a0; +0x188 (line index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x188

## Behavioral explanation
Increments line index +0x188 (cap 999) and, while below 999, advances the caller's element pointer by 4 (next line-record slot).

## Notes / uncertainty
Like advance_line_index but also advances caller's line-record pointer by 4 while below 999 ceiling. Fully determined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed1a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
