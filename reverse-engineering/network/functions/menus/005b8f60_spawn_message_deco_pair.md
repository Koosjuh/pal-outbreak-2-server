# 0x005b8f60 spawn_message_deco_pair

| field | value |
|---|---|
| Original address | 0x005b8f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8f60 |
| Resolved name | spawn_message_deco_pair |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b8da0, FUN_005b8e40
**Callees:** FUN_00618ba0
**Referenced globals:** 0x006c4fcf uRam=msg flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fcf

## Behavioral explanation
Allocates two decoration display nodes (icon ids 0x7b/0x7c or 0x7f/0x80 by mode) with callback FUN_005ba190; carries type/subtype in +2/+3 and data ptr in +0x10.

## Notes / uncertainty
Allocates two frame widgets (icons 0x7b/0x7c or 0x7f/0x80), second tagged +0x38=1 (animated path in deco_widget_cb). Top/bottom vs L/R resolved by pos tables in callback.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8f60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
