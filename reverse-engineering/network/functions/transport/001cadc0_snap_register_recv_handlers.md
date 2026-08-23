# 0x001cadc0 snap_register_recv_handlers

| field | value |
|---|---|
| Original address | 0x001cadc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cadc0 |
| Resolved name | snap_register_recv_handlers |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cac50, FUN_001cac60, FUN_001d4d24
**Referenced globals:** 0x35b9e0=snap handle; 0x3688c8/d0/d8=ring state; 0x248850=write ptr; 0x36a8f0=misc
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes the recv ring state and registers the datagram callbacks (types 0x12/0x14/0x13/0x15) with the SN@P transport via FUN_001d4d24.

## Notes / uncertainty
Recv-path init: resets ring state to empty then registers 4 transport event callbacks via FUN_001d4d24 (0x12->0x1cac70, 0x14->snap_recv_ring_push, 0x13/0x15->0x1cadb0). Meaning of event types 0x12/0x13/0x15 and 0x36a8f0 aux word not decoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cadc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
