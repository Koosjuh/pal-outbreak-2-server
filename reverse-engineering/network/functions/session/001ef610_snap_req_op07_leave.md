# 0x001ef610 snap_req_op07_leave

| field | value |
|---|---|
| Original address | 0x001ef610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef610 |
| Resolved name | snap_req_op07_leave |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e2b3c, FUN_001ee3f0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 4B); 0x37cf20 (2B); 0x37cf22 (2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x07 (leave) with a 32-bit id + two 16-bit fields, returns result.

## Notes / uncertainty
SIF-RPC op07 leave, body {u32 id +0x1c, u16 +0x20, u16 +0x22} (cmd7, len 0x28). Same body shape as op08 stub FUN_001ef690. Two u16 fields' meaning unpinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
