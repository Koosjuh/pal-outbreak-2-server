# 0x005beb40 register_objtype_0xad_slot

| field | value |
|---|---|
| Original address | 0x005beb40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005beb40 |
| Resolved name | register_objtype_0xad_slot |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005befa0
**Callees:** FUN_005be0a0, FUN_005beba0
**Referenced globals:** 0x6ca97e slot handle-id; 0x7018d0 object registry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a task slot then registers a type-0xad object (via FUN_005beba0), stamping the returned id into the slot handle field.

## Notes / uncertainty
Allocates net_task_slot(type1) via 005be0a0, registers type-0xad object (005beba0->0xad) into handle-id slot+0x16 (0x6ca97e) only; no short-id, no name copy. Called from room-record handler reg 005befa0. Runtime dispatch of 0xad unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005beb40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
