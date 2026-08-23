# 0x005ae3e0 overlay_dialog_dispatch_54b4

| field | value |
|---|---|
| Original address | 0x005ae3e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae3e0 |
| Resolved name | overlay_dialog_dispatch_54b4 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005ae510, FUN_005ae630, FUN_005ae750, FUN_005b1d10, FUN_005b9110
**Referenced globals:** obj +0x5196/+0x51a2/+0x45a/+0x455/+0x42c/+0x54b4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Per-frame gate for a modal/overlay: only runs when flags 0x5196==0,0x51a2!=0,+0x45a set and screen id not in {0,5,6,7}; dispatches on +0x54b4 to ae510/ae630/ae750; returns handled flag.

## Notes / uncertainty
Per-frame gate+dispatch for the 54b4 wait/countdown overlay; runs only when +0x5196==0,+0x51a2!=0,+0x45a!=0,kind not in {0,5,6,7},+0x455==0; phase switch +0x54b4 -> ae510/ae630/ae750. Returns handled flag. Cue 0x4c meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
