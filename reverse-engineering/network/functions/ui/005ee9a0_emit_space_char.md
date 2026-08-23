# 0x005ee9a0 emit_space_char

| field | value |
|---|---|
| Original address | 0x005ee9a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee9a0 |
| Resolved name | emit_space_char |
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
Writes a space (0x20) into the glyph buffer +0x20, advances the index and the run width.

## Notes / uncertainty
Writes 0x20 to glyph buf, advances run x by +0x181. Unambiguous; param_1 unused.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee9a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
