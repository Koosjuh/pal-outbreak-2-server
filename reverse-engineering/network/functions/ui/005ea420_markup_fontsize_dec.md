# 0x005ea420 markup_fontsize_dec

| field | value |
|---|---|
| Original address | 0x005ea420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea420 |
| Resolved name | markup_fontsize_dec |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70, FUN_005ef200, FUN_005ef220
**Referenced globals:** +0x124 (cur size slot idx); +0x168 (size-level array); +0x2d3 (size digit char); +0x2d4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x124; +0x168

## Behavioral explanation
Font-size-smaller tag: decrements the size level at +0x168[+0x124] (min 1), writes ASCII digit (level+0x30) to +0x2d3, brackets layout flush.

## Notes / uncertainty
Decrease-font tag: size_levels[+0x168][cur_slot +0x124] floored at 1, emits ASCII digit to +0x2d3, bracketed by layout save/flush. Decremented value written to digit field, not observably back to the array here (persist may be in FUN_005eef70).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
