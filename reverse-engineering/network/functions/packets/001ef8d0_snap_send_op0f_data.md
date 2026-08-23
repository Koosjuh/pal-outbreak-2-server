# 0x001ef8d0 snap_send_op0f_data

| field | value |
|---|---|
| Original address | 0x001ef8d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef8d0 |
| Resolved name | snap_send_op0f_data |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee590
**Callees:** FUN_001069a8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37cf1e (len, 2B); 0x37cf20 (payload); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x0f
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x0f carrying a caller data buffer (length clamped to 0xc00), returns result.

## Notes / uncertainty
Semaphore-serialized SIF-RPC for app opcode 0x0f; marshals id/len/payload into static 0x37cf00, clamps len to 0xc00, RPC bytes len+0x26, reply status at 0x37bf18. NOTE possible semaphore leak on len<1 path (WaitSema without matching SignalSema) — decompiler-ordering artifact or unreachable; flag for runtime check.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
