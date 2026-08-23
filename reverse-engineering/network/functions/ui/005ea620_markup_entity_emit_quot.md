# 0x005ea620 markup_entity_emit_quot

| field | value |
|---|---|
| Original address | 0x005ea620 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea620 |
| Resolved name | markup_entity_emit_quot |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eee00
**Referenced globals:** +4; +0xd8e4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4

## Behavioral explanation
Entity handler: appends ASCII '"' (0x22) to the output buffer with 0x7d overflow guard.

## Notes / uncertainty
Emitter; char 0x22 '"'.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea620.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
