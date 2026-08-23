# 0x005bfa70 start_enter_txn

| field | value |
|---|---|
| Original address | 0x005bfa70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfa70 |
| Resolved name | start_enter_txn |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad030, FUN_005ad680
**Callees:** FUN_005be0a0, FUN_005bf0e0, FUN_005c1f30
**Referenced globals:** 0x700680 seq reset; 0x6ca97c req-table selector (stride 0x20); 0x6ca97e req-table txn id; 0x6fec04 registry-A key src
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a request slot (FUN_005be0a0) and sends a reliable USER enter/register (func_0x001dc9fc, cb 0x5bfb40), recording selector+txn id into request table 0x6ca97c/0x6ca97e; stages channel-0.

## Notes / uncertainty
ENTER/JOIN launcher: alloc req slot, op6e selector (FUN_005c1f30), send op06 member-JOIN (func_0x001dc9fc) with registryA room id, cb enter_reply_handler; records selector/txn in 0x6ca97c/7e stride 0x20. Does not set 0x6ff2b1.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfa70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
