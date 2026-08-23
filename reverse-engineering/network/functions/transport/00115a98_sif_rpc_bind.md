# 0x00115a98 sif_rpc_bind

| field | value |
|---|---|
| Original address | 0x00115a98 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00115a98 |
| Resolved name | sif_rpc_bind |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0017ee60, FUN_001ef310, FUN_001f1fe0
**Callees:** FUN_00115088, FUN_001154c8, FUN_00115570
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
EE-side SIF RPC bind (cmd 0x80000009); node pool 0x25e440; sync(sema)/async(bit0) paths; returns 0/-1/-2/-3. sceSifClientData-style layout inferred, not cross-validated on live struct.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00115a98.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
