# 0x005ede80 render_option_label

| field | value |
|---|---|
| Original address | 0x005ede80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ede80 |
| Resolved name | render_option_label |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e9790, FUN_005e98e0
**Callees:** FUN_005d92f0
**Referenced globals:** iRam007012a0; +0x18 (max col); +0x7f1 (out buf); +0x8f1 (flag); +0x186/+0xe96b
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
Trims leading/trailing whitespace of a label string, measures its display length into max-col +0x18, and on the draw pass renders it via FUN_005d92f0 (e.g. a select/option label).

## Notes / uncertainty
Trims leading/trailing ws (ctype DAT_006491b0 bit2), counts multibyte columns into line_maxcol, draws via FUN_005d92f0 with one-shot flag +0x8f1. Purpose of +0x7f1/+0x8f1 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ede80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
