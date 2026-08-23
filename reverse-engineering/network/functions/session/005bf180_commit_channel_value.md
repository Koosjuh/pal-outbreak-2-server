# 0x005bf180 commit_channel_value

| field | value |
|---|---|
| Original address | 0x005bf180 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf180 |
| Resolved name | commit_channel_value |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bfb40, FUN_005bfd80, FUN_005c0400, FUN_005c05c0, FUN_005c1c80
**Callees:** —
**Referenced globals:** 0x6ce5ce ch0; 0x6ce5cf ch1; 0x6ce5d0 ch2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ce5ce; 0x6ce5cf; 0x6ce5d0

## Behavioral explanation
Commits staged channel value (0x6ce5c4/c5/c6) into committed slot (0x6ce5ce/cf/d0) for channel 0/1/2.

## Notes / uncertainty
committed[ch]=staging[ch]. Corrected prior note: committed[1] (0x6ce5cf) is a byte sign-in state, NOT a callback pointer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
