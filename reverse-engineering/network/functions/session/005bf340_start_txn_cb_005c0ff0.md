# 0x005bf340 start_txn_cb_005c0ff0

| field | value |
|---|---|
| Original address | 0x005bf340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf340 |
| Resolved name | start_txn_cb_005c0ff0 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acea0, FUN_005ad680
**Callees:** —
**Referenced globals:** 0x6cb9dc busy flag; 0x6cb9d0 arg(&0xf); 0x6cb9b8 tick cb ptr; 0x6cb9bc user cb; 0x6cb9d8 state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cb9dc busy

## Behavioral explanation
Guarded async-txn launcher: if idle (cRam006cb9dc==0) latches param(&0xf) at 0x6cb9d0, arms tick callback FUN_005c0ff0, stores user-cb param_3, resets state.

## Notes / uncertainty
Single-slot async-op launcher (state block A 0x6cb9b8..dc, arg&0xf, tick=FUN_005c0ff0). Busy-mutex, returns -1 if in flight. Upgraded Medium->High: launcher mechanics certain; driven op (FUN_005c0ff0) outside slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
