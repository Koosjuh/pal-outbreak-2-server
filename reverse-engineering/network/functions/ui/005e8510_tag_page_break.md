# 0x005e8510 tag_page_break

| field | value |
|---|---|
| Original address | 0x005e8510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8510 |
| Resolved name | tag_page_break |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef4f0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: page-break / paragraph flush via FUN_005ef4f0.

## Notes / uncertainty
Delegates to FUN_005ef4f0 (page/paragraph flush). ef4f0 body not decompiled — page-break role inferred from address family + ABI, not from its body.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
