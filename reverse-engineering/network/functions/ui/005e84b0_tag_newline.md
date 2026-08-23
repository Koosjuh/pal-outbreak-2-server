# 0x005e84b0 tag_newline

| field | value |
|---|---|
| Original address | 0x005e84b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e84b0 |
| Resolved name | tag_newline |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: emits a newline/flush into the layout buffer (FUN_005ef040).

## Notes / uncertainty
Hard newline via FUN_005ef040 (flush+line-feed). Byte-identical twin of 0x005e84d0; which markup byte dispatches here vs twin unknown (dispatch table not dumped).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e84b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
