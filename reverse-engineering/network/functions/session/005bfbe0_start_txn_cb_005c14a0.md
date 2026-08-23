# 0x005bfbe0 start_txn_cb_005c14a0

| field | value |
|---|---|
| Original address | 0x005bfbe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfbe0 |
| Resolved name | start_txn_cb_005c14a0 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad530, FUN_005f78c0
**Callees:** —
**Referenced globals:** 0x6cba04 busy flag; 0x6cb9f8 arg(&0xf); 0x6cb9e0 tick cb(=FUN_005c14a0); 0x6cb9e4 user cb; 0x6cba00 state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cba04 busy

## Behavioral explanation
Guarded async-txn launcher: if idle (cRam006cba04==0) latches param(&0xf)@0x6cb9f8, arms tick callback FUN_005c14a0, stores user cb, resets state.

## Notes / uncertainty
Twin launcher, state block B (0x6cb9e0..0x6cba04, arg&0xf, tick=FUN_005c14a0). Room-slot/list callers. Driven op FUN_005c14a0 outside slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfbe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
