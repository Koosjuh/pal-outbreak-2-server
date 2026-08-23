# 0x001ef830 snap_req_op0e_query3

| field | value |
|---|---|
| Original address | 0x001ef830 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef830 |
| Resolved name | snap_req_op0e_query3 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e4bec, FUN_001ee430
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf1e/0x37bf22/0x37bf24 (3 out values); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x0e
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x0e with a 16-bit id and returns three 16-bit out-values plus result.

## Notes / uncertainty
3-word getter; copies out A@+0x1e,B@+0x22,C@+0x24 UNCONDITIONALLY (contrast op16). Field meanings inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef830.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
