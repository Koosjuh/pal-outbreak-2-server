# 0x001ebed0 subpool_init

| field | value |
|---|---|
| Original address | 0x001ebed0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebed0 |
| Resolved name | subpool_init |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e1e4c, FUN_001eb22c, FUN_001ebae0, FUN_001ecd28
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x70/0x72/0x74 tier watermarks; +0x5c/0x60/0x62/0x66/0x68/0x6c fill counters

## Behavioral explanation
Builds the 3-tier reliable-transport buffer pool: allocates a 0x78 conn/pool struct, sets tier MTUs (0xec/0x22c/0x3ac) and high-water counts (6/3/3), inits three lists (+0/+0x14/+0x28), and preallocates param_2/3/4 buffers into each tier.

## Notes / uncertainty
Builds 3-tier reliable buffer pool: MTUs 0xec/0x22c/0x3ac, high-water 6/3/3, lists at +0x00/+0x14/+0x28; preallocs n0/n1/n2. -6999 OOM; publishes *out only on full success. usable payload = MTU-0x2c.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
