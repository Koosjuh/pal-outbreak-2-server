# 0x005bd940 register_named_net_handler

| field | value |
|---|---|
| Original address | 0x005bd940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd940 |
| Resolved name | register_named_net_handler |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3790, FUN_005f99c0, FUN_005fada0, FUN_0062dc40, FUN_0062de90
**Callees:** FUN_005bdef0, FUN_005be0a0
**Referenced globals:** 0x7004d0 name scratch buf; 0x7005b0/0x7005c0 aux copy; 0x6ca97c slot short-id; 0x6ca97e slot handle-id; 0x6febac session/transport ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers a named network message handler: zeroes scratch 0x7004d0, copies param name in, allocates a task slot and stores a transport-derived message id into the slot's short-ID fields.

## Notes / uncertainty
Allocates net_task_slot(type1) via 005be0a0, stores msgtype short-id (005bdef0->0x6ca97c) and transport handle-id (001de470,cb=0x5bd8c0->0x6ca97e). Slot base 0x6ca968 stride0x20. Purpose of 0x7005c0->0x7005b0 aux copy inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
