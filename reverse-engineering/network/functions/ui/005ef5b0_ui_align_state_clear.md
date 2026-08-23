# 0x005ef5b0 ui_align_state_clear

| field | value |
|---|---|
| Original address | 0x005ef5b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef5b0 |
| Resolved name | ui_align_state_clear |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb0f0, FUN_005eb1d0, FUN_005f0e10, FUN_005f10a0
**Callees:** —
**Referenced globals:** +0xf16 pending h-align; +0xf17 pending v-align; +0xf18 pending extra/color
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf16; +0xf17; +0xf18

## Behavioral explanation
Clears the pending horizontal/vertical align + extra-value scratch (ctx+0xf16=+0xf17=0, +0xf18=0xffffffff).

## Notes / uncertainty
Clears pending align scratch +0xf16=+0xf17=0, +0xf18=0xffffffff (subset of the +0xf10 block ui_child_attr_init zeroes). +0xf18 color-vs-numeric ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef5b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
