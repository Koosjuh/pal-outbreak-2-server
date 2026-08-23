# 0x001ef710 snap_req_op0a_member_list

| field | value |
|---|---|
| Original address | 0x001ef710 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef710 |
| Resolved name | snap_req_op0a_member_list |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e2c7c
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x0a (member-list) with a single 16-bit id, returns result.

## Notes / uncertainty
Synchronous op0x0a member-list RPC: writes u16 id @0x37cf1c, sends via FUN_001ef400 (reqlen0x22=0x20+2, resplen0x20, template0x37df10), returns u16 @0x37bf18. Return field semantics (status/count/handle) unproven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
