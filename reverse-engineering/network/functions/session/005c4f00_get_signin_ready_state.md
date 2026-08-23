# 0x005c4f00 get_signin_ready_state

| field | value |
|---|---|
| Original address | 0x005c4f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4f00 |
| Resolved name | get_signin_ready_state |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bbc20, FUN_005be330, FUN_005c2f40, FUN_005c3490, FUN_005c3b10
**Callees:** —
**Referenced globals:** 0x6ce5cf signin-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006ce5cf signin-progress

## Behavioral explanation
Returns tri-state from sign-in flag: 0 if ==1 (ready), -1 if <2 (pending), else 1.

## Notes / uncertainty
Tri-state gate on committed ch1 (0x6ce5cf): ==1->0 ready, ==0->-1 pending, >=2->1 other. Meaning of state>=2 not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
