# 0x005c0470 create_slot_sm_arm

| field | value |
|---|---|
| Original address | 0x005c0470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0470 |
| Resolved name | create_slot_sm_arm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f99c0, FUN_0062de90
**Callees:** —
**Referenced globals:** 0x6cc01a config table (0x25 u16); 0x6cba7c SM guard; 0x6cba58 pump fnptr=FUN_005c3490; 0x6cba5c SM ctx; 0x6cba78 SM step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cba7c guard; 0x6cba78 step

## Behavioral explanation
Copies a 37-entry (0x25 u16) config table from param_1 into 0x6cc01a, then arms an async screen state-machine (guard 0x6cba7c, pump FUN_005c3490, ctx=param_2).

## Notes / uncertainty
CORE create-room path. Stages 37xu16 create-request into 0x6cc01a then arms create-slot SM (guard 0x6cba7c, step=owner_substate 0x6cba78, pump FUN_005c3490). Pump emits create over conn, on commit sets 0x6ff2b1=1/0x6cbc7e=0x10/screen 0x18. Request-block layout unmapped; op04-vs-op26 not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
