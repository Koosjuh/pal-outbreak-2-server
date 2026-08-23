# 0x005c04f0 send_op6e_with_name

| field | value |
|---|---|
| Original address | 0x005c04f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c04f0 |
| Resolved name | send_op6e_with_name |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fada0, FUN_0062dc40
**Callees:** FUN_005be0a0, FUN_005bf0e0, FUN_005c1ff0
**Referenced globals:** 0x6ca97c/0x6ca97e txn slots; 0x6fee68 room record base; 0x6febac SN@P conn
**Referenced strings:** —
**Referenced opcodes:** 0x6e
**State vars:** —

## Behavioral explanation
Allocates a txn slot, builds op 0x6e with a string payload (via 1ff0), sends the reliable command (func_0x001dcdfc, arg param_2 + count 1) for room record param_1, and sets room slot 2.

## Notes / uncertainty
Txn + app-cmd 0x6e + reliable op06 create/enter carrying room handle and a name/pw string; stages slot-2 candidate. The +0x16 txn_id store is attributed to void FUN_005bf0e0 in the decompile (ABI/reg leftover, non-behavioral). Title-vs-password depends on caller.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c04f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
