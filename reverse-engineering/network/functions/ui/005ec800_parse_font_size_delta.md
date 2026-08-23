# 0x005ec800 parse_font_size_delta

| field | value |
|---|---|
| Original address | 0x005ec800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec800 |
| Resolved name | parse_font_size_delta |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ef220
**Callees:** —
**Referenced globals:** iRam007012a0; +0x124/+0x168 (current font)
**Referenced strings:** + / - (size sign)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a font-size token: leading '-'/'+' gives a relative size (clamped 1..7) else absolute digit, defaulting to the current font index.

## Notes / uncertainty
HTML <font size> +n/-n relative to base 3, clamped 1..7; else absolute digit; default=current size from table +0x168[+0x124]. Absolute path itself unclamped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
