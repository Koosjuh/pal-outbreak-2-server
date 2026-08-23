# 0x0060f5e0 snap_socket_recv_blocking

| field | value |
|---|---|
| Original address | 0x0060f5e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f5e0 |
| Resolved name | snap_socket_recv_blocking |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e160
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Transport primitive: spins func_0x0011a3c8(handle,0,0,&tmp) until >=0, then spins func_0x0011a5d0(handle) until >=0.

## Notes / uncertainty
Blocking recv+consume: spins syscall 0x11a3c8 until >=0 then 0x11a5d0 until >=0. Syscall identities opaque (recv/peek vs open/accept inferred from pattern).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f5e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
