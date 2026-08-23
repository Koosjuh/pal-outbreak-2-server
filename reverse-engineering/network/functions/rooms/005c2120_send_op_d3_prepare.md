# 0x005c2120 send_op_d3_prepare

| field | value |
|---|---|
| Original address | 0x005c2120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2120 |
| Resolved name | send_op_d3_prepare |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ffa90
**Callees:** FUN_005be0a0, FUN_005c2250
**Referenced globals:** 0x7005ad request flag; 0x7004d0 request buffer; 0x6ca97c/0x6ca97e txn slots; 0x6febac conn
**Referenced strings:** —
**Referenced opcodes:** 0xd3
**State vars:** 0x7005ad

## Behavioral explanation
Sets flag 0x7005ad=1, allocates a txn, builds op 0xd3 (2250) and sends the reliable command (func_0x001de470, arg buffer 0x7004d0) with reply slot registration.

## Notes / uncertainty
Improved name: arms 0x7005ad=1, txn + app-cmd 0xd3, sends reliable op0c PREPARE (func_0x001de470) carrying the 0x7004d0 enter block; reply 0x5c21c0. On-wire op is 0x0c, not 0xd3 (app-cmd/wire duality). Refresh-vs-retry semantics vs 3490's PREPARE unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
