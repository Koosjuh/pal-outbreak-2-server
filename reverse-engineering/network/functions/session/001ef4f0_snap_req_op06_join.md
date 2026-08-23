# 0x001ef4f0 snap_req_op06_join

| field | value |
|---|---|
| Original address | 0x001ef4f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef4f0 |
| Resolved name | snap_req_op06_join |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee6e0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf00 (RPC request buffer); 0x37bf00 (RPC response buffer); 0x37bf18 (reply result word)
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x06 (member join/enter) with no body, returns reply result word.

## Notes / uncertainty
SIF-RPC op06 member-JOIN, empty body (cmd6, len 0x20). Documented full RPC framework: WaitSema(0x37aee0)/stage 0x37cf00/sceSifCallRpc via FUN_001ef400+FUN_00115c68/result 0x37bf18/SignalSema. cmd==app opcode (inference, corroborated by PACKET_INDEX). Parallel to direct-EE op06 builders; which path is live in PAL online flow unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef4f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
