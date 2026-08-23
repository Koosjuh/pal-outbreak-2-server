# 0x005ede30 emit_line_break

| field | value |
|---|---|
| Original address | 0x005ede30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ede30 |
| Resolved name | emit_line_break |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e9d50, FUN_005e9e00
**Callees:** FUN_005d9290
**Referenced globals:** iRam007012a0; +0x18 (col width acc); +0x186/+0xe96b (pass/suppress)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xe96b

## Behavioral explanation
Handles a <br>-like break: zeroes field +0x18 and, on the draw pass, emits via FUN_005d9290.

## Notes / uncertainty
Hard <br>: zeroes line_maxcol(+0x18), draws FUN_005d9290(+0x6f0 descriptor) on draw pass. Descriptor format/draw semantics unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ede30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
