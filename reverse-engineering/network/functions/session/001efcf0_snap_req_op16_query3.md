# 0x001efcf0 snap_req_op16_query3

| field | value |
|---|---|
| Original address | 0x001efcf0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efcf0 |
| Resolved name | snap_req_op16_query3 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e2c7c
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf1e (out 2B); 0x37bf20 (out 4B); 0x37bf24 (out 2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x16
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x16 with a 16-bit id; on success (result==0) returns three out-values (2B,4B,2B).

## Notes / uncertainty
Guarded getter: copies out A@+0x1e(u16),B@+0x20(u32),C@+0x24(u16) only if result==0. Control flow confirmed; fields inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efcf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
