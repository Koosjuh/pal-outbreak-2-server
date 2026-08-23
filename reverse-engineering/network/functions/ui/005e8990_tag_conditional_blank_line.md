# 0x005e8990 tag_conditional_blank_line

| field | value |
|---|---|
| Original address | 0x005e8990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8990 |
| Resolved name | tag_conditional_blank_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef0e0
**Referenced globals:** +0x188 (page idx); +0x153c (per-page table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x188; +0x153c

## Behavioral explanation
Markup tag handler: consumes arg, then flushes only if the per-page value at +0x153c[page] is non-zero.

## Notes / uncertainty
Cond-linefeed then extra line-feed if per-page +0x153c[page] (page=+0x188, stride4) !=0. Whether +0x153c slot is bool/count/flags and who sets it unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8990.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
