# 0x005bff20 start_txn_cb_005c1770

| field | value |
|---|---|
| Original address | 0x005bff20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bff20 |
| Resolved name | start_txn_cb_005c1770 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8ec0, FUN_0062d9f0, FUN_0062dc40
**Callees:** —
**Referenced globals:** 0x6cba2c busy flag; 0x6cba20 arg(&0xff); 0x6cba08 tick cb(=FUN_005c1770); 0x6cba0c user cb; 0x6cba28 state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cba2c busy

## Behavioral explanation
Guarded async-txn launcher: if idle (cRam006cba2c==0) latches param(&0xff)@0x6cba20, arms tick callback FUN_005c1770, stores user cb, resets state.

## Notes / uncertainty
Twin launcher, state block C (0x6cba08..2c). DISTINGUISHING: arg&0xff (8-bit id) vs 0xf twins; tick=FUN_005c1770; callers are room-enter/join (0x62d9f0/0x62dc40). Driven op outside slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bff20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
