# 0x00608300 login_connect_state_machine

| field | value |
|---|---|
| Original address | 0x00608300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608300 |
| Resolved name | login_connect_state_machine |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_001b3720, FUN_005ac380, FUN_005af340, FUN_005c80a0, FUN_005c8810, FUN_005de2a0, FUN_00606ac0, FUN_00606f10, FUN_00608840, FUN_00618b60, FUN_006235f0
**Referenced globals:** 0x0070cda8 login-state; 0x003c8a80 conn-mode; 0x00701e20 req-buf; 0x00701f20 flag; 0x006c4fd7 flag; 0x00701070 session-ptr; 0x0064a110 fmt
**Referenced strings:** 0x8711fd (fmt); 0x8710fc (fmt); 0x64a110 (fmt)
**Referenced opcodes:** —
**State vars:** cRam0070cda8; cRam003c8a80; uRam00701f20

## Behavioral explanation
Multi-phase connect/login state machine on cRam0070cda8 (0,1,2,'c',3,4,5,6): sprintf request into 0x701e20 from format strings by conn-mode, drives connect/poll (005c80a0/005c8810), branches on results (-100/-1/1/2).

## Notes / uncertainty
Main login SM (cRam0070cda8); template by conn-mode (0x8711fd auth / 0x8710fc / 0x64a110 default); poll codes -100/-1/1/2; error 0x85→FUN_00606ac0. Odd success(1) w/ mode2 routing to error handler unexplained.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
