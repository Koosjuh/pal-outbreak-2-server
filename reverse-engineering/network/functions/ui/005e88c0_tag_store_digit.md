# 0x005e88c0 tag_store_digit

| field | value |
|---|---|
| Original address | 0x005e88c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e88c0 |
| Resolved name | tag_store_digit |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef200, FUN_005ef220
**Referenced globals:** 0x6494b0 (digit remap table); 0x648248 (delimiter); +0x2d3 (digit field)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2d3

## Behavioral explanation
Markup tag handler: maps preceding byte through digit table (0x6494b0), stores ASCII digit at +0x2d3, advances parse ptr past delimiter 0x648248, then flushes.

## Notes / uncertainty
Normalizes preceding char via remap table 0x6494b0, stores 1-char digit at +0x2d3, advances cursor past delimiter 0x648248; bracketed by ef200/ef220 (state push/pop+palette). Remap table contents and downstream consumer of +0x2d3 not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e88c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
