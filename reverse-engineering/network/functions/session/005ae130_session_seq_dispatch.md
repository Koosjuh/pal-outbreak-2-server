# 0x005ae130 session_seq_dispatch

| field | value |
|---|---|
| Original address | 0x005ae130 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae130 |
| Resolved name | session_seq_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ade20, FUN_005b4a50
**Callees:** FUN_005ae1e0, FUN_005ae210, FUN_005ae260, FUN_005ae2c0, FUN_005ae310, FUN_005ae3a0, FUN_005ae3c0
**Referenced globals:** obj +0x993(seq cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session/connect sub-sequence dispatcher: switches on screen-obj +0x993 (0..6) to the seven ordered connect steps ae1e0..ae3c0.

## Notes / uncertainty
Ordered connect sub-seq dispatcher on obj+0x993 (0..6 -> ae1e0..ae3c0, default 0). Returns selected step status (-1/1=done,0=running). Only step 4 decompiled in this batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
