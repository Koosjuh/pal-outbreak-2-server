# 0x001ef690 snap_req_op08_leave

| field | value |
|---|---|
| Original address | 0x001ef690 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef690 |
| Resolved name | snap_req_op08_leave |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e2ffc
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 4B); 0x37cf20 (2B); 0x37cf22 (2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x08
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x08 (leave variant) with 32-bit id + two 16-bit fields, returns result.

## Notes / uncertainty
Structure Confirmed (id32+a16+b16, semaphore-guarded shared-scratch RPC via FUN_001ef400/FUN_00115c68 handle 0x37df10). Leave semantics from opcode map; the two 16-bit fields (slot/room/reason) unproven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
