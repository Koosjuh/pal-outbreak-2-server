# 0x00618510 periph_set_unit

| field | value |
|---|---|
| Original address | 0x00618510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618510 |
| Resolved name | periph_set_unit |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006101d0, FUN_00610830
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +5 unit

## Behavioral explanation
Setter: stores a unit/index byte into the peripheral descriptor field +5.

## Notes / uncertainty
Trivial setter desc+5=unit. Range-check happens downstream (0x618460 <=1).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
