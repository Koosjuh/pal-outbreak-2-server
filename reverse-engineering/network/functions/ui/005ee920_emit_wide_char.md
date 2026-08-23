# 0x005ee920 emit_wide_char

| field | value |
|---|---|
| Original address | 0x005ee920 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee920 |
| Resolved name | emit_wide_char |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eea60, FUN_005f3420
**Callees:** —
**Referenced globals:** iRam007012a0; +0x1c (buf idx); +0x20 (glyph buf); +0x181 (advance)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a multibyte (0x80-lead-bit) character sequence from the input into the glyph output buffer +0x20, advances the write index +0x1c, and adds glyph advance width to the run.

## Notes / uncertainty
Copies one multibyte glyph (0x80 lead) to glyph buf +0x20, adds single advance +0x181. param_2 record layout beyond +4 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
