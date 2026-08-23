# 0x005ea4a0 markup_fontsize_inc

| field | value |
|---|---|
| Original address | 0x005ea4a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea4a0 |
| Resolved name | markup_fontsize_inc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70, FUN_005ef200, FUN_005ef220
**Referenced globals:** +0x124; +0x168; +0x2d3; +0x2d4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x124; +0x168

## Behavioral explanation
Font-size-larger tag: increments size level at +0x168[+0x124] (max 7), writes ASCII digit (level+0x30) to +0x2d3, brackets layout flush.

## Notes / uncertainty
Mirror of dec; ceiling 7 -> valid level range [1,7]. Same persist-writeback uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea4a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
