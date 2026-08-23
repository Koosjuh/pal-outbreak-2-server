# 0x001ef7d0 snap_req_op0c_prepare

| field | value |
|---|---|
| Original address | 0x001ef7d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef7d0 |
| Resolved name | snap_req_op0c_prepare |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee650
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x0c
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x0c (prepare) with a single 16-bit id, returns result.

## Notes / uncertainty
op0c PREPARE, single-u16-id. Confirmed anchor + live handoff capture (op0c at create boundary). Whether id is room-handle vs slot unverified at runtime.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef7d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
