# 0x005b76f0 markup_render_runs

| field | value |
|---|---|
| Original address | 0x005b76f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b76f0 |
| Resolved name | markup_render_runs |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b7cd0, FUN_005b7de0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b75b0, FUN_005b7f70
**Referenced globals:** 0x6ca600 (run array); 0x6ca300 (per-run text scratch); DAT_00638f60 (glyph-width table); fRam006ca860/864/868 (pen pos); uRam006ca878 (current color/attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ca881; cRam006ca886; uRam006ca878

## Behavioral explanation
Walk the parsed run array (0x6ca600, up to 0x1d runs), apply per-run attribute bits (color, alignment cases 0-9), advance pen (fRam006ca860/864) and blit each run's text via FUN_005af1e0 using glyph-width table DAT_00638f60.

## Notes / uncertainty
Line renderer: per-run flag-bit switch (align/color/newline/tab cases 0-9) + text blit via FUN_005af1e0; align modes 5/6/7. Double color-latch likely decompiler artifact; 4 dead blocks omitted.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b76f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
