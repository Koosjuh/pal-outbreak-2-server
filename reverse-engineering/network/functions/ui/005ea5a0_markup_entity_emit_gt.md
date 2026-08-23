# 0x005ea5a0 markup_entity_emit_gt

| field | value |
|---|---|
| Original address | 0x005ea5a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea5a0 |
| Resolved name | markup_entity_emit_gt |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eee00
**Referenced globals:** +4 (out len); +0xd8e4 (flush)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4

## Behavioral explanation
Entity handler: appends ASCII '>' (0x3e) to the output buffer with the same 0x7d overflow guard.

## Notes / uncertainty
Byte-identical emitter; char 0x3e '>'.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea5a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
