# 0x00601ac0 format_template_pct_tokens

| field | value |
|---|---|
| Original address | 0x00601ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601ac0 |
| Resolved name | format_template_pct_tokens |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00601c00
**Callees:** FUN_0062fea0
**Referenced globals:** 0x649d48/0x649d50 numeric format strings
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
String templater: walks a template (FUN_0062fea0 string 0x45), replacing %1/%2 tokens (delimiter 0x25 '%') with formatted args and emitting the rest verbatim into the output buffer.

## Notes / uncertainty
printf-lite templater over localized string id 0x45: expands %1/%2 (2-char fields via fmt 0x649d48, fallback 0x649d50). Used by render_room_timer for mm:ss. Exact fmt-string text not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
