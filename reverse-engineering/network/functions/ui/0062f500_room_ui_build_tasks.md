# 0x0062f500 room_ui_build_tasks

| field | value |
|---|---|
| Original address | 0x0062f500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f500 |
| Resolved name | room_ui_build_tasks |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d730
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates UI display objects (FUN_00618ba0) and installs render callbacks: one FUN_0062f5b0 task (id 0x121) plus two FUN_0062f710 tasks (ids 0xd9+i), all bound to param_1.

## Notes / uncertainty
Sprite-task factory: 1 title task (f5b0, id 0x121) + 2 blink tasks (f710, ids 0xd9/0xda) via sprite_slot_alloc @0x7133f0. Skips build if first alloc fails; two blink allocs unchecked. Sprite-id meanings unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
