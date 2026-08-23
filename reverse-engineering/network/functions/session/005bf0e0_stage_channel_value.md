# 0x005bf0e0 stage_channel_value

| field | value |
|---|---|
| Original address | 0x005bf0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf0e0 |
| Resolved name | stage_channel_value |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bfa70, FUN_005bfd80, FUN_005c0400, FUN_005c04f0, FUN_005c0e30
**Callees:** —
**Referenced globals:** 0x6ce5c4 stage ch0; 0x6ce5c5 stage ch1; 0x6ce5c6 stage ch2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ce5c4; 0x6ce5c5; 0x6ce5c6

## Behavioral explanation
Stages a byte into one of 3 per-channel staging slots (0x6ce5c4/c5/c6) selected by param_1 (0/1/2).

## Notes / uncertainty
staging[ch]=val for ch 0/1/2 (0x6ce5c4/c5/c6); out-of-range=no-op. Part of stage/commit/clear/read 3-channel bank. Channel-0 semantics unknown; ch1=sign-in, ch2=room/scenario.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf0e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
