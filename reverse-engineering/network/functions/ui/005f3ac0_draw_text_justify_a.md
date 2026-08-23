# 0x005f3ac0 draw_text_justify_a

| field | value |
|---|---|
| Original address | 0x005f3ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3ac0 |
| Resolved name | draw_text_justify_a |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eef70
**Callees:** FUN_005ec170, FUN_005f3420, FUN_005f3930
**Referenced globals:** iRam007012a0(0x188, 0x1540 line array, 0xd894, 0x2518, 0x04)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186

## Behavioral explanation
Text draw entry (justify variant A): runs word-wrap measure then line-flush over the text context.

## Notes / uncertainty
Single-line text draw: measure_wordwrap + flush_line, pen<-origin, place-mode stores block line-Y (0x2518), clears busy+consumed. No trailing newline (distinguishes from B/C). TextReq layout beyond byte0 unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
