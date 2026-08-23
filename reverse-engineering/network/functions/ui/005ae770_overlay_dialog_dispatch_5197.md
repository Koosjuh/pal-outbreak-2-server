# 0x005ae770 overlay_dialog_dispatch_5197

| field | value |
|---|---|
| Original address | 0x005ae770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae770 |
| Resolved name | overlay_dialog_dispatch_5197 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005ae8a0, FUN_005ae9b0, FUN_005aeae0, FUN_005b1d10, FUN_005b9110
**Referenced globals:** obj +0x5196/+0x45a/+0x455/+0x42c/+0x5197
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sibling of ae3e0: per-frame gate for a second overlay, dispatching on +0x5197 to ae8a0/ae9b0/aeae0 when screen id not in {0,5,6,7,0xc} and flags allow; returns handled flag.

## Notes / uncertainty
Sibling of ae3e0: gate+dispatch for the 5197 list/roster overlay; runs only when +0x5196!=0 (its own active latch), kind not in {0,5,6,7,0xc}; phase +0x5197 -> ae8a0/ae9b0/aeae0. Why kind 0xc excluded here only, inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
