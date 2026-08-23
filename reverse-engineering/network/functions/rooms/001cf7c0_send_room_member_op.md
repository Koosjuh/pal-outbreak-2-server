# 0x001cf7c0 send_room_member_op

| field | value |
|---|---|
| Original address | 0x001cf7c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf7c0 |
| Resolved name | send_room_member_op |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ab460, FUN_001cbc20, FUN_001ce070, FUN_001cf360, FUN_001cf6a0
**Referenced globals:** 0x460d08/0x460500 send buffers
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Selects channel (idx*8 + 0x1400/0x1600 by param_3), presets attrs, allocs 0x20 (tag 2/3), and emits a member op via FUN_001ce070; if param_3==1 also calls FUN_001cf6a0.

## Notes / uncertainty
Reliable room member op: channel slot*8+0x1600(role1)/0x1400, priority 3/2, encodes record via FUN_001ce070(id,id,3,0,target), target forced 0xff broadcast when role!=1. Opcode/record layout not pinned; sibling to cf3e0.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf7c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
