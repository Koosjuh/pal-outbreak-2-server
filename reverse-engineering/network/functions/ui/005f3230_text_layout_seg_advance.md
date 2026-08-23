# 0x005f3230 text_layout_seg_advance

| field | value |
|---|---|
| Original address | 0x005f3230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3230 |
| Resolved name | text_layout_seg_advance |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f2710, FUN_005f2b10, FUN_005f2e50
**Callees:** FUN_005ec170, FUN_005ed1a0, FUN_005ed430, FUN_005ef780
**Referenced globals:** iRam007012a0(text-render context: 0x186 mode, 0xd8ce/0xd8d6 pen, 0x1c cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186 (render mode flag)

## Behavioral explanation
Text-render helper: advances the pen and returns accumulated line width in the text context.

## Notes / uncertainty
Text-segment terminator: place-mode writes glyph start-X, runs pen copy/finalize/reset trio + glyph emit, returns advanced pen-X. Callee emit/finalize roles (005ed430/005ed1a0/005ec170/005ef780) inferred, not traced. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
