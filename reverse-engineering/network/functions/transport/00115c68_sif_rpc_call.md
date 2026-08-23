# 0x00115c68 sif_rpc_call

| field | value |
|---|---|
| Original address | 0x00115c68 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00115c68 |
| Resolved name | sif_rpc_call |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0017f0e8, FUN_0017f158, FUN_0017f230, FUN_0017f2b8, FUN_0017f4f8, FUN_0017f818, FUN_0017f948, FUN_0017faa8, FUN_0017fc10, FUN_001ef400, FUN_001f22a0, FUN_001f2348, FUN_001f25e0
**Callees:** FUN_00115088, FUN_00115250, FUN_001154c8, FUN_00115570
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
EE-side SIF RPC call (cmd 0x8000000a); send/recv bufs+lens on node; bit0=async, bit1=no-cache-wb (FUN_00115250 dcache writeback, could be invalidate); callback in async. Field names follow sceSifClientData convention.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00115c68.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
