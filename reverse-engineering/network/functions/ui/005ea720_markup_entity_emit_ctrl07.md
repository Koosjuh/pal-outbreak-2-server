# 0x005ea720 markup_entity_emit_ctrl07

| field | value |
|---|---|
| Original address | 0x005ea720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea720 |
| Resolved name | markup_entity_emit_ctrl07 |
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
Entity handler: appends byte 0x07 (control/BEL or an internal markup control code) to the output buffer with 0x7d overflow guard.

## Notes / uncertainty
Renamed from _0x07: emitter appends control byte 0x07 (non-printable; likely internal inline-formatting sentinel). Exact renderer meaning of 0x07 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
