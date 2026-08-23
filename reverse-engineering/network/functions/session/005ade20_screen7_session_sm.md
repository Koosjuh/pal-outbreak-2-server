# 0x005ade20 screen7_session_sm

| field | value |
|---|---|
| Original address | 0x005ade20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ade20 |
| Resolved name | screen7_session_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005addb0, FUN_005ae130, FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005b14b0, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005bea90, FUN_00618b60
**Referenced globals:** 0x870f10(session table src); 0x6ca090(shadow copy,0x1d0); 0x6c4fd7; obj +0xe/+0x16/+0x993; 0x701e20/0x701e10; 0x35ba80
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fd7

## Behavioral explanation
Lobby screen-7 state machine (+0xe): runs the session/connect sequence, snapshots a 0x1d0-byte table 0x870f10->0x6ca090, diffs it (memcmp), and on change pushes it via 5bea90 (cb 0x5ae0b0), driving the ae130 sub-sequence.

## Notes / uncertainty
Per-frame screen-7 session SM (obj+0xe, 9 steps). Snapshots 0x1d0-byte table 0x870f10->shadow 0x6ca090, runs ae130 connect sub-seq, memcmp-diffs and re-pushes via 5bea90 on change; bounded wait <=300 frames. Table semantics + 00109728 format spec unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ade20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
