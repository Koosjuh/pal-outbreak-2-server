# 0x005bfdd0 abort_txn_invoke_cb

| field | value |
|---|---|
| Original address | 0x005bfdd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfdd0 |
| Resolved name | abort_txn_invoke_cb |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb790
**Callees:** FUN_005bf230
**Referenced globals:** 0x6cbc84 status flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc84

## Behavioral explanation
Clears status flag 0x6cbc84 and invokes the pending callback via FUN_005bf230 (cancel/teardown path).

## Notes / uncertainty
Cancel path: 0x6cbc84=0 then dispatch pending cb via FUN_005bf230. bf230 internals not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfdd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
