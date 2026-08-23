# 0x005eea60 layout_text_run

| field | value |
|---|---|
| Original address | 0x005eea60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eea60 |
| Resolved name | layout_text_run |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eef70, FUN_005ef040, FUN_005ef0e0
**Callees:** FUN_005ec8b0, FUN_005ee840, FUN_005ee920, FUN_005ee9a0, FUN_005ee9f0
**Referenced globals:** iRam007012a0; +0x10 (container width); +0x181 (advance); +0xd8c0 (run x); +0x18b/+0x18d (nowrap/state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0x18b

## Behavioral explanation
Main text tokenizer/word-wrapper: skips leading whitespace, iterates chars emitting via emit_char/emit_space/emit_wide, flushing the run (flush_text_run) whenever the pending width would overflow container width +0x10.

## Notes / uncertainty
Core word-wrap loop: tokenizes text (FUN_005ec8b0), collapses ws, emits via emit_char/space/wide, flushes+wraps on overflow (nowrap +0x18b guards ASCII/multibyte, 0x07 always wraps). Measure pass clamps line height +0x180.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eea60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
