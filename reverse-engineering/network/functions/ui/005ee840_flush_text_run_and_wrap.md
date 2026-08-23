# 0x005ee840 flush_text_run_and_wrap

| field | value |
|---|---|
| Original address | 0x005ee840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee840 |
| Resolved name | flush_text_run_and_wrap |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005eea60
**Callees:** FUN_005ec170, FUN_005ed0c0, FUN_005ed1a0, FUN_005ed430
**Referenced globals:** iRam007012a0; +0x1c (glyph buf len); +0x20 (glyph buffer); +0xd8c0/+0xd8bc/+0xd8c8 (cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Finalizes the current text run: records run width (+0xd8c8), NUL-terminates the glyph buffer, draws any underline/rule (layout_and_draw_rule), then resets the cursor and advances the line.

## Notes / uncertainty
Renamed from _with_rule: mid-run flush — records run width, NUL-terminates, draws FUN_005ed0c0, resets buf, advances line via ed430/ed1a0/ec170. No separate rule primitive; split of the 3 advance calls inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
