# 0x001f27c8 iopdev_rpc_poll

| field | value |
|---|---|
| Original address | 0x001f27c8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f27c8 |
| Resolved name | iopdev_rpc_poll |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d42e0, FUN_001d4450, FUN_001d44f0, FUN_001d4630, FUN_001f1fe0
**Callees:** FUN_00115e60, FUN_001f2878
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync/poll for the async device RPCs: mode0=WaitSema-block then read result (FUN_001f2878)+SignalSema; mode1=sceSifCheckStatRpc(FUN_00115e60) idle?read:busy(1); else -0xb. FUN_001f2878/00115e60 identities inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f27c8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
