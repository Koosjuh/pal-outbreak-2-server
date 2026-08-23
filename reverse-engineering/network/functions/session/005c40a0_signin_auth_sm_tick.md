# 0x005c40a0 signin_auth_sm_tick

| field | value |
|---|---|
| Original address | 0x005c40a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c40a0 |
| Resolved name | signin_auth_sm_tick |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c5810, FUN_005c5ad0
**Referenced globals:** 0x6cbc08/0c/0d (SM state/busy/reply); 0x700420/424/428/470 (auth result blocks/flags); 0x6fbe57 (final auth result); 0x6cbbec (completion cb); 0x70047d (mode)
**Referenced strings:** DIO (0x4f494400)
**Referenced opcodes:** —
**State vars:** cRam006cbc08; cRam006cbc0c; cRam006cbc0d; uRam006fbe57

## Behavioral explanation
The sign-in/auth state machine tick (0x6cbc08): sequences two 'DIO' transport transactions (0x1e094c and 0x1e0ed8 against result blocks 0x700424/0x700428), evaluates the 0x700470 result flags to set uRam006fbe57, then fires the completion callback.

## Notes / uncertainty
Auth SM pump: linear steps 0..5->'c'/6 driving two 'DIO' (0x4f494400) transport txns against 0x700424/0x700428, then completion cb. 0x40000000 flag = elevated success. Step-1 advance is external (register cb); DIO txn semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c40a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
