# 0x005ed430 reset_line_cursor

| field | value |
|---|---|
| Original address | 0x005ed430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed430 |
| Resolved name | reset_line_cursor |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed460, FUN_005ee840, FUN_005eed40, FUN_005f3230, FUN_005f3310, FUN_005f39d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Resets a line-cursor struct: zeroes x, advances baseline y by the element height, mirrors into the start x/y fields.

## Notes / uncertainty
Resets caller line-cursor struct: x=0, baseline y += element height, mirror to cur, clear byte flag@+16. Field roles inferred; pure (no globals).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
