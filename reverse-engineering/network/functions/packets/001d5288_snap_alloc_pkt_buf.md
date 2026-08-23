# 0x001d5288 snap_alloc_pkt_buf

| field | value |
|---|---|
| Original address | 0x001d5288 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5288 |
| Resolved name | snap_alloc_pkt_buf |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d533c, FUN_001db7e8, FUN_001dbd0c, FUN_001dbefc, FUN_001dc0b8, FUN_001dc310, FUN_001dc508, FUN_001dc804, FUN_001dc9fc, FUN_001dcbf4, FUN_001dcdfc, FUN_001dd07c, FUN_001dd1dc, FUN_001dd33c, FUN_001dd5f8, FUN_001dd840, FUN_001dda88, FUN_001ddc60, FUN_001ddda0, FUN_001ddee8, FUN_001de0c0, FUN_001de298, FUN_001de470, FUN_001de648, FUN_001de840, FUN_001de9e8, FUN_001ded08, FUN_001df044, FUN_001df1d8, FUN_001df380, FUN_001df66c, FUN_001df9a8, FUN_001dfad0, FUN_001dfbf8, FUN_001dfda0, FUN_001dff7c, FUN_001e0188, FUN_001e05c8, FUN_001e0774, FUN_001e094c, FUN_001e0ed8
**Callees:** FUN_001ec1f8, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x520 pool

## Behavioral explanation
Allocates a packet buffer of size param_2+0x14 from the pool and reserves a 0x10 header; frees+nulls on header-reserve failure.

## Notes / uncertainty
Outbound message buffer factory (40+ callers). pool_alloc(conn+0x520, size+0x14, class=1, flag=1) then reserve 0x10 header; free+NULL on reserve failure. Choke point where sub-pool-2 watermark exhaustion becomes a NULL. 0x14 slack split unverified.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5288.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
