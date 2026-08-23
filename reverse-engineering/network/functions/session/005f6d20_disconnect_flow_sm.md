# 0x005f6d20 disconnect_flow_sm

| field | value |
|---|---|
| Original address | 0x005f6d20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6d20 |
| Resolved name | disconnect_flow_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6aa0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005af340, FUN_005b14b0, FUN_005b24c0, FUN_005b9110, FUN_005f4550, FUN_005f6a20, FUN_005f70a0, FUN_005f7270, FUN_00606f10, FUN_00608840, FUN_00618b60, FUN_006235e0, FUN_0062fea0
**Referenced globals:** 0x3c8a80; param+0x11 (step); param+0x97b (context)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x11 (step 0-0xc); param+0x16 (dwell timer); param+0x97b (context)

## Behavioral explanation
Longer state machine on +0x11 (0-0xc) for the disconnect/return flow: runs wait-overlay FUN_005f7270, error/retry handling, teardown FUN_005b24c0/FUN_005b9110(0x4c), and context-byte (+0x97b) branch back to lobby/menu screens.

## Notes / uncertainty
Leave/disconnect/return-to-menu step SM on +0x11; exit dispatched by reason byte +0x97b (3=lobby,7=conn-lost,8=net-teardown). Reason enum values inferred from step-8/12 branch conditions, not a trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6d20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
