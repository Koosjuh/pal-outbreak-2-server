# 0x001eedf0 snap_rpc_cmd01_failtest

| field | value |
|---|---|
| Original address | 0x001eedf0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eedf0 |
| Resolved name | snap_rpc_cmd01_failtest |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001ef540
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Calls FUN_001ef540(a, b, a|~(a&b)) with two words from caller; returns boolean (true iff result <0), a predicate/test.

## Notes / uncertainty
RPC cmd 0x01 predicate; KEY FINDING: 3rd arg a|~(a&b) reduces to constant 0xFFFFFFFF. Returns -1 on RPC<0 else 0. Prior filename 'f0540' mislabels callee ef540.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eedf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
