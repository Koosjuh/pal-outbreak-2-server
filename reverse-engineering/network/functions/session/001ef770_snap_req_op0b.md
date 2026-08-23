# 0x001ef770 snap_req_op0b

| field | value |
|---|---|
| Original address | 0x001ef770 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef770 |
| Resolved name | snap_req_op0b |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e3f98, FUN_001e4bec, FUN_001ee5f0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x0b
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x0b with a single 16-bit id, returns result.

## Notes / uncertainty
Single-u16-id stub, result-only. Opcode 0x0b not in confirmed anchor map; likely room/member query (3 callers in enter paths). Semantics inferred, structure certain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
