# 0x001d46ec snap_conn_create

| field | value |
|---|---|
| Original address | 0x001d46ec |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d46ec |
| Resolved name | snap_conn_create |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46a0
**Callees:** FUN_00102678, FUN_00102790, FUN_00106b60, FUN_00109d70, FUN_00109eb8, FUN_001d5138, FUN_001d51e0, FUN_001e1468, FUN_001e14e8, FUN_001e1590, FUN_001e1608, FUN_001e1d88, FUN_001e1e4c, FUN_001e2010, FUN_001e234c, FUN_001e2394, FUN_001e2610, FUN_001e270c, FUN_001e2928, FUN_001e3100, FUN_001eb22c, FUN_001ebed0, FUN_001ecdc0
**Referenced globals:** 0x0025b78c conn-ptr (published here)
**Referenced strings:** SNAP-SWAN (built byte-by-byte 0x53 0x4e 0x41 0x50 0x2d 0x53 0x57 0x41 0x4e); MR (via 0x259290); CL (via 0x2592a0)
**Referenced opcodes:** —
**State vars:** 0x0025b78c conn-ptr; conn+0x145/0x146 MR/CL params (0x22,4)

## Behavioral explanation
Allocates+zeroes the 0x624 connection struct, stamps the 'SNAP-SWAN' magic, creates the UDP socket (AF_INET/DGRAM), binds a port from 2000 upward, wires sub-pools, and publishes it to the global conn ptr.

## Notes / uncertainty
Transport constructor: allocs 0x624 conn, 'SNAP-SWAN' magic@+0x4d4, reliable_pool init@+0x520 (matches struct), send/reorder queues+node+subpool, UDP socket, bind loop from port 2000, publishes DAT_0025b78c, MR/CL defaults 0x22/4 + arg parse; error codes -1/-2/-3/-4/-5/-8/-99. Uncertainty: MR/CL offset cross vs 6ee0.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d46ec.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
