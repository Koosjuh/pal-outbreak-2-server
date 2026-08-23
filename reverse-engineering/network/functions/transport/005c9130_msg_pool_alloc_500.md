# 0x005c9130 msg_pool_alloc_500

| field | value |
|---|---|
| Original address | 0x005c9130 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9130 |
| Resolved name | msg_pool_alloc_500 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8ed0
**Callees:** FUN_005dfde0
**Referenced globals:** 0x701068+0x5ffc0 (pool ptr array, 500 x 4); LAB_005c8090 (default handler)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates and links a pool of 500 message buffers (FUN_005dfde0), initializing each buffer's handler ptrs to default LAB_005c8090 and header fields to 0.

## Notes / uncertainty
Builds 500-buffer msg pool at arena(0x701068)+0x5ffc0 via FUN_005dfde0, default handler LAB_005c8090 at buf+0x14/+0x18; null-terminates on alloc fail. Full per-buffer layout beyond 0x5f undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
