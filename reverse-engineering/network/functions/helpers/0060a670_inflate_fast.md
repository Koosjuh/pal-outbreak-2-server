# 0x0060a670 inflate_fast

| field | value |
|---|---|
| Original address | 0x0060a670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060a670 |
| Resolved name | inflate_fast |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00609c60
**Callees:** —
**Referenced globals:** 0x0064b530 bit-mask-table
**Referenced strings:** invalid distance code; invalid literal/length code
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
zlib inflate_fast: fast-path Huffman literal/match decode loop, copying matches from the sliding window with wraparound handling.

## Notes / uncertainty
zlib hot inner loop; 3 window-copy variants (wrap-split/wrap-contig/non-wrap). Un-read epilogues transcribed structurally not per-exit. Op bits 0x10/0x20/0x40/0x0f documented.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060a670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
