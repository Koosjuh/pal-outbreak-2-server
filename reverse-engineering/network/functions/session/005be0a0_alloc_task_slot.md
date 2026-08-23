# 0x005be0a0 alloc_task_slot

| field | value |
|---|---|
| Original address | 0x005be0a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be0a0 |
| Resolved name | alloc_task_slot |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bd940, FUN_005bdb00, FUN_005beb40, FUN_005bebf0, FUN_005bfa70, FUN_005bfe00, FUN_005bffa0, FUN_005c02b0, FUN_005c04f0, FUN_005c0750, FUN_005c0a00, FUN_005c2120, FUN_005c2390, FUN_005c28f0, FUN_005c5ad0
**Callees:** —
**Referenced globals:** 0x6ca980 slot state byte; 0x6ca981 slot flag; 0x6ca968 tick-cb; 0x6ca96c destroy-cb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca980 slot-occupied state

## Behavioral explanation
Allocates the first free entry (state byte==0) in the 128-slot callback/task table at 0x6ca960 (stride 0x20), storing state, a tick callback (+0x968) and a destroy callback (+0x96c); returns index or -1.

## Notes / uncertainty
Allocator for 128-slot task/callback registry (base 0x6ca968 stride 0x20). Slot layout derived: +0x00 tick_cb, +0x04 destroy_cb, +0x14 key16, +0x16 txn16, +0x18 state(0 free/1 armed/2 tick), +0x19 flag. 15 callers; foundational. state values beyond {0,1,2} unclear.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be0a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
