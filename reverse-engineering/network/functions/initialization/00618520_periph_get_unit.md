# 0x00618520 periph_get_unit

| field | value |
|---|---|
| Original address | 0x00618520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618520 |
| Resolved name | periph_get_unit |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006101d0, FUN_00612020, FUN_006120a0, FUN_00613fb0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +5 unit

## Behavioral explanation
Getter: returns the unit/index byte from peripheral descriptor field +5.

## Notes / uncertainty
Trivial getter returning desc+5 unit. Unit semantics depend on unidentified peripheral.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
