# 0x005b7de0 draw_markup_string_ex

| field | value |
|---|---|
| Original address | 0x005b7de0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7de0 |
| Resolved name | draw_markup_string_ex |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b6e10
**Callees:** FUN_005af2c0, FUN_005b7320, FUN_005b76f0, FUN_005b7f00
**Referenced globals:** 0x6ca860/864/868/86c (pen/state); uRam006ca87c (cursor); cRam006ca881 (parser end)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ca881

## Behavioral explanation
Extended markup draw entry (6 params incl. extra layout args) — same tokenize/render loop as 7cd0 with param4/param5 passed to the renderer.

## Notes / uncertainty
Extended variant of 7cd0 forwarding param4/param5 as width/height overrides to renderer; no null-check; only caller (6e10) passes 0,0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7de0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
