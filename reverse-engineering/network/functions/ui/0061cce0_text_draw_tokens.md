# 0x0061cce0 text_draw_tokens

| field | value |
|---|---|
| Original address | 0x0061cce0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061cce0 |
| Resolved name | text_draw_tokens |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061c9f0, FUN_0061d080, FUN_0061d210
**Callees:** —
**Referenced globals:** 0x669bec/0x669bf0 glyph ptrs; 0x669c00 color palette; uRam0071535a/cRam00715359 substituted values
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Renders a string with inline control tokens after '%'(0x25): 'v'=version, '1'/'2'=button-icon glyphs, 'y'/'s'=state-formatted values, advancing X per glyph with per-color runs.

## Notes / uncertainty
Rich-text line renderer, %-escape tokens v(version)/1/2(button glyphs)/y(numeric uRam0071535a)/s(selector cRam00715359), per-token X advance, palette 0x669c00 clamp <=4/5, 199-seg cap. func_0x001aeff0 mono/proportional selector meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061cce0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
