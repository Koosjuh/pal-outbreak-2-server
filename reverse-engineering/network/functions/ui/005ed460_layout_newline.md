# 0x005ed460 layout_newline

| field | value |
|---|---|
| Original address | 0x005ed460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed460 |
| Resolved name | layout_newline |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed530, FUN_005ee010, FUN_005ee610
**Callees:** FUN_005ec170, FUN_005ed1a0, FUN_005ed430
**Referenced globals:** iRam007012a0; +0x12/+0xd8c4/+0xd8bc (margins/x); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Performs a line break: on draw pass records x, resets the line cursor (reset_line_cursor), advances the line index, and returns the new left x.

## Notes / uncertainty
Hard line break: measure-pass records end x, clears +0x1c, resets cursor +0xd8bc, advances index+ptr, returns new left x. FUN_005ec170 (x recompute) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
