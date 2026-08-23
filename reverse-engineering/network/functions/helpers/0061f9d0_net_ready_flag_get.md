# 0x0061f9d0 net_ready_flag_get

| field | value |
|---|---|
| Original address | 0x0061f9d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f9d0 |
| Resolved name | net_ready_flag_get |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60
**Callees:** —
**Referenced globals:** 0x7152f1 ready flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam007152f1

## Behavioral explanation
Returns 1 if ready-flag 0x7152f1 bit0 set else 2 (ready/not-ready poll used by screen SMs).

## Notes / uncertainty
Polls 0x7152f1 bit0 -> 1 ready / 2 not-ready (never 0). Producer is screen_reset_lobby. Note many callers only test ==0, which this never returns.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f9d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
