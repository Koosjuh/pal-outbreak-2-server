# 0x001f05c0 snap_rpc_op25_put_blob

| field | value |
|---|---|
| Original address | 0x001f05c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f05c0 |
| Resolved name | snap_rpc_op25_put_blob |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee900
**Callees:** FUN_001069a8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
SN@P EE->IOP RPC stub, transport fno 0x25: variable-length payload upload (subcode u16 @+0x1c, len u16 @+0x1e, memcpy payload @+0x20, ssize 0x124). Sole caller FUN_001ee900 sends op25(1,4,buf). Mechanism High; domain meaning of subcode/payload inferred (IOP-side external).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f05c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
