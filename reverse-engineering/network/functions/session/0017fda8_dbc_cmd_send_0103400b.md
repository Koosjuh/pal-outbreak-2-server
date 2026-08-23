# 0x0017fda8 dbc_cmd_send_0103400b

| field | value |
|---|---|
| Original address | 0x0017fda8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017fda8 |
| Resolved name | dbc_cmd_send_0103400b |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_0017f948
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
DBC-transport send-RPC wrapper (IOP dbcman, sceSifCallRpc fn 0x8000131b, client 0x27afb0, semaphore-guarded); packs two length-prefixed blobs into fixed 0x28-byte msg, sends as DBC cmd 0x0103400b. Header [len_b,len_a], data [blob_a|blob_b] cross-ordered; branch-free; result discarded. Uncertainty: blob semantics + cmd meaning unknown; len_a+len_b<=32 inferred not enforced; runtime-unvalidated.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017fda8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
