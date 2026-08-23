# 0x005bffa0 start_registerB_user_txn

| field | value |
|---|---|
| Original address | 0x005bffa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bffa0 |
| Resolved name | start_registerB_user_txn |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe500, FUN_005fe8d0, FUN_0062e440
**Callees:** FUN_005be0a0, FUN_005c1e70
**Referenced globals:** 0x6ca97c req-table selector; 0x6ca97e req-table txn id; 0x6fee68 registry-B key src (stride 0x24)
**Referenced strings:** USER (0x55534552)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a request slot, builds selector FUN_005c1e70(2,..), sends a reliable USER register (func_0x001dd5f8, tag 0x55534552, cb 0x5c0060) keyed from registry-B (0x6fee68), recording selector+txn id.

## Notes / uncertainty
USER register keyed off registry-B (room handles, 0x6fee68 30x0x24): op7b selector (FUN_005c1e70), op09 unreliable USER send (func_0x001dd5f8, tag USER, cb 0x5c0060). Renamed from 'maxi' (no MAXI tag in code — only USER). Reliable(regA) vs unreliable(regB) op09 split observed, rationale unpinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bffa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
