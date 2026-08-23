# 0x001d5ae4 snap_send_coalesce

| field | value |
|---|---|
| Original address | 0x001d5ae4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5ae4 |
| Resolved name | snap_send_coalesce |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** FUN_001d5768, FUN_001eb2d4, FUN_001eb4dc, FUN_001eb5ac, FUN_001eb858, FUN_001ebb90, FUN_001ebbd0, FUN_001ebc10, FUN_001ebc4c, FUN_001ebca8, FUN_001ebd04, FUN_001ebd54, FUN_001ebd7c, FUN_001ec1f8, FUN_001ec9e0, FUN_001ed360, FUN_001ed60c, FUN_001ed634, FUN_001ed6bc, FUN_001ed864, FUN_001ed924
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x60 send pool; pkt flag 0x800 (merged/multi)

## Behavioral explanation
Aggregates queued send buffers (conn+0x60 pool) into combined datagrams under the merge policy and a 0x37f size budget, splitting/joining nodes and tagging merged packets with the 0x800 bit.

## Notes / uncertainty
Multi-pass send coalescer: merges small descriptors into <=0x37f-byte datagrams in seq order, sets 0x800 coalesced bit; ed864 returns -0x1f3e boundary sentinel. High-uncertainty: precise merge/split semantics and ebbd0(set) vs ebc10(clear) flag identities inferred; C block is a control-flow skeleton.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5ae4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
