# 0x001c2da0 netbuf_ctx_init

| field | value |
|---|---|
| Original address | 0x001c2da0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c2da0 |
| Resolved name | netbuf_ctx_init |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2f80, FUN_001c3180, FUN_001c3250, FUN_001c32b0, FUN_001c3300, FUN_001c3320, FUN_001c3340
**Callees:** FUN_00106b60, FUN_00108840, FUN_0010a4f0, FUN_001c3420
**Referenced globals:** 0x365ac0 conn-obj/mode; 0x3684b0 tx-buf; 0x3687c0 rx-buf; 0x35ccb0 =0x278f
**Referenced strings:** (0x248740 cfg)
**Referenced opcodes:** —
**State vars:** 0x365ac0 mode; 0x365b04

## Behavioral explanation
Initializes the 0x365xxx socket/session object (buffers, tx/rx pointers 0x3684b0/0x3687c0, mode in 0x365ac0, timestamp) and seeds rate-clamp via FUN_001c3420.

## Notes / uncertainty
Shared ctor for netbuf_ctx @0x365ac0 (UDP framing ctx, distinct from snap_connection). Field map derived; buffer-descriptor offsets +0x28/+0x38/+0x1c cross-confirmed by flush path. 0x100/0x300/0x278f meanings inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c2da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
