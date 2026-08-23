# 0x00603d50 txn_set_action_7

| field | value |
|---|---|
| Original address | 0x00603d50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603d50 |
| Resolved name | txn_set_action_7 |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b1a30, FUN_006052f0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+1; ctx+0xe..0x11

## Behavioral explanation
Sets room-context action byte at +1 to 7 (candidate leave/op07) and clears the retry counter.

## Notes / uncertainty
Sibling setter: ctx+0x01=7, clears +0x0e counter. Value 7 aligns with op07 leave (inferred); reached from FUN_005b1a30 + FUN_006052f0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
