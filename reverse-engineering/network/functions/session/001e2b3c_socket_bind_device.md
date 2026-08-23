# 0x001e2b3c socket_bind_device

| field | value |
|---|---|
| Original address | 0x001e2b3c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2b3c |
| Resolved name | socket_bind_device |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00103de8, FUN_001e2a28, FUN_001ef610
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** slot+2 type; slot+4 state(-1 unbound)

## Behavioral explanation
Binds a socket descriptor to a device endpoint via FUN_001ef610 (using addr+4 / port+2), storing the returned low-level id into slot+0; rejects listening(type1) or already-bound slots.

## Notes / uncertainty
BSD bind-family: fd->slot via 001e2a28, rejects listening(type+2==1, errno0x6d) & non-unbound(state+4!=-1, errno0xe), else 001ef610(addr@+4,port@+2) -> slot[0]. bind-vs-connect ambiguous (001ef610 undecoded).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2b3c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
