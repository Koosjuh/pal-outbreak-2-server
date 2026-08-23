# 0x006075e0 enter_confirm_state_handler

| field | value |
|---|---|
| Original address | 0x006075e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006075e0 |
| Resolved name | enter_confirm_state_handler |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** FUN_001b3720, FUN_005af310, FUN_005af340, FUN_005b24c0, FUN_005be8c0, FUN_005be900, FUN_00606ac0, FUN_00618b60
**Referenced globals:** 0x003c8a80 conn-mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam003c8a80

## Behavioral explanation
State-4 enter/confirm screen: steps through send (005be8c0) / poll (005be900) / async-init (005af310), on completion clears conn-mode 3c8a80 and returns via FUN_00606ac0.

## Notes / uncertainty
arm->send->await->finish substep ladder on req[1]; finish clears conn-mode 0x3c8a80 + resets SM. Exact opcode emitted at send substep (op0c/op26/op2b) not pinned; callee roles inferred by position.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006075e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
