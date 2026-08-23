# 0x005bfe00 start_leave_txn

| field | value |
|---|---|
| Original address | 0x005bfe00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfe00 |
| Resolved name | start_leave_txn |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c1c80
**Callees:** FUN_005be0a0, FUN_005c2080
**Referenced globals:** 0x6ca97c req-table selector (stride 0x20); 0x6ca97e req-table txn id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a request slot (FUN_005be0a0), builds selector FUN_005c2080(1), sends a reliable txn (func_0x001dd07c, cb 0x5bfe90), recording selector+txn id in request table 0x6ca97c/0x6ca97e.

## Notes / uncertainty
LEAVE launcher: alloc req slot, op70 selector (FUN_005c2080), send op07 leave (func_0x001dd07c, zero-len reliable), cb leave_reply_handler; records selector/txn stride 0x20.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfe00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
