# 0x001efda0 snap_req_op17

| field | value |
|---|---|
| Original address | 0x001efda0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efda0 |
| Resolved name | snap_req_op17 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e4bec
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x17
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x17 with a single 16-bit id, returns result.

## Notes / uncertainty
Single-u16-id stub, result-only. Co-caller with op0e/op16 in FUN_001e4bec; likely op16's action/commit pair. Inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efda0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
