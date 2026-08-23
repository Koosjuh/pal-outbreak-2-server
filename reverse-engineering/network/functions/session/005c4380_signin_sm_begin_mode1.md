# 0x005c4380 signin_sm_begin_mode1

| field | value |
|---|---|
| Original address | 0x005c4380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4380 |
| Resolved name | signin_sm_begin_mode1 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627b00
**Callees:** —
**Referenced globals:** 0x6cbc0c (busy flag); 0x6fbe58 (work buffer); 0x7003fd (credential copy); 0x70047d (mode=1); 0x6cbbe8 (tick fn); 0x6cbbec (callback)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbc0c; uRam0070047d

## Behavioral explanation
Variant of signin_sm_begin that sets uRam0070047d=1 before registering the same tick fn (FUN_005c40a0) and callback; starts the auth SM in the alternate mode.

## Notes / uncertainty
Byte-identical to 0x5c3ef0 except sets mode 0x70047d=1 (online path -> skips FUN_005c5810 offline finalize). Which UI action picks mode 1 vs 0 not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
