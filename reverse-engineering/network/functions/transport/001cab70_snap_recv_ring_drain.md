# 0x001cab70 snap_recv_ring_drain

| field | value |
|---|---|
| Original address | 0x001cab70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cab70 |
| Resolved name | snap_recv_ring_drain |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001caed0
**Callees:** FUN_001069a8, FUN_00106a58, FUN_001cac50, FUN_001cac60
**Referenced globals:** 0x36a900=recv ring buffer; 0x3688c8=ring fill; 0x248850=ring write ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3688c8=bytes available

## Behavioral explanation
Drains up to param_2 bytes from the receive ring buffer at 0x36a900 into the caller buffer under the mutex, compacting the ring and updating the fill counter.

## Notes / uncertainty
Ring consumer: copies min(fill,want) bytes from 0x36a900 to dst, memmove-compacts remainder to base, updates fill(0x3688c8)+wptr(0x248850); -16 if transport down. Linear 4096-byte ring (base 0x36a900,end 0x36b900). memmove length arg elided by decompiler but pointers unambiguous.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cab70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
