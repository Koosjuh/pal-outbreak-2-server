# 0x005bacf0 return_zero_stub_f0

| field | value |
|---|---|
| Original address | 0x005bacf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bacf0 |
| Resolved name | return_zero_stub_f0 |
| Subsystem | unknown |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_005b9150, FUN_00602700
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Stub returning 0 (8 bytes); used as a placeholder string/value in FUN_005b9150 sprintf calls.

## Notes / uncertainty
8-byte return 0; result feeds a sprintf in FUN_005b9150 (inferred stubbed name/label getter -> empty). Role unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bacf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
