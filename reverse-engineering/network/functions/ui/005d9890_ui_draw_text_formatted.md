# 0x005d9890 ui_draw_text_formatted

| field | value |
|---|---|
| Original address | 0x005d9890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9890 |
| Resolved name | ui_draw_text_formatted |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ecf20
**Callees:** FUN_005cab10
**Referenced globals:** 0x643390: format-string literal
**Referenced strings:** (format string @0x643390)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay: formats a string into a 256-byte stack buffer via sprintf-style helper then emits text draw kind 0x0e.

## Notes / uncertainty
memset+sprintf(fmt@0x643390) then kind0x0e emit. ANOMALY: formatted stack buffer not passed to emitter - text source at emit time (global scratch vs dropped alias) unresolved; held at Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
