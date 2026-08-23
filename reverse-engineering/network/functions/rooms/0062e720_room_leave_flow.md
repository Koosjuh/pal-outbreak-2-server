# 0x0062e720 room_leave_flow

| field | value |
|---|---|
| Original address | 0x0062e720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e720 |
| Resolved name | room_leave_flow |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062e3c0
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005c0e30, FUN_005f74d0, FUN_00617a00, FUN_00637180
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 leave-step; struct+0x42b screen(=0x23); struct+0x997 leave-result; struct+0x146b flag

## Behavioral explanation
Leave-room flow: sets screen +0x42b=0x23, sends leave request via FUN_005c0e30(...,0x62f480); on reply branches on +0x997 (1->FUN_005f74d0, 2->FUN_00617a00 lobby reset).

## Notes / uncertainty
REWROTE from shallow 'classified' to full reconstruction. Leave-room SM: step0 sends leave op via FUN_005c0e30 (cb 0x62f480), step2 routes by result +0x997 (1->room-list FUN_005f74d0, 2->lobby FUN_00617a00). Relevant to parking-lot exit-room stall. Uncertainty: exact leave opcode (op07/op08 family).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
