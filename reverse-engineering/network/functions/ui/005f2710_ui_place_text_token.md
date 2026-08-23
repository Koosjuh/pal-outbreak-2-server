# 0x005f2710 ui_place_text_token

| field | value |
|---|---|
| Original address | 0x005f2710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2710 |
| Resolved name | ui_place_text_token |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed530
**Callees:** FUN_005f3230
**Referenced globals:** +0x186 pass; +0xd894 node idx; +0xd8ce..+0xd8dc cursors; +0x2500 max-width, +0x2530 node flags, +0x251a/+0x251c pad
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8d2

## Behavioral explanation
Places a text token at the current cursor, wrapping to the next line via FUN_005f3230 when it would overflow content width; updates x/y out-params and max-width in measure mode.

## Notes / uncertainty
Inline word placement with wrap (f3230) on content-right overflow; measure pass grows max-content width; nowrap flag +0x2530 bit2. d8dx gap cursor roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f2710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
