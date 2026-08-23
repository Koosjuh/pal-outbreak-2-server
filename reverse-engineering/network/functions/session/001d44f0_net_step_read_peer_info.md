# 0x001d44f0 net_step_read_peer_info

| field | value |
|---|---|
| Original address | 0x001d44f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d44f0 |
| Resolved name | net_step_read_peer_info |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d4630, FUN_001f2348, FUN_001f27c8
**Referenced globals:** 0x24da90 sub-handler table; 0x36d568 state index; 0x36d5b0/0x36d6d0 peer/config struct (0x88); 0x36d580/0x36d588 id fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0036d570; sRam0036d560; cRam0036d568

## Behavioral explanation
Step: dispatches sub-handler (0x24da90 table), calls 0x1d4630 status, snapshots a 0x88-byte peer/config struct (0x36d6d0) and builds a 7-byte id field at 0x36d58a.

## Notes / uncertainty
3-way state step over 0x36d5xx adapter block: dispatch-table handshake, then net_query_status, snapshot 0x88 config struct, build 7-byte hw-id (MAC-like, inferred). 001f2348/001f27c8 library internals + self-copy memcpy undecoded; no caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d44f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
