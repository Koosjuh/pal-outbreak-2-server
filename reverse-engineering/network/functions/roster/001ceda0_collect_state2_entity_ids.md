# 0x001ceda0 collect_state2_entity_ids

| field | value |
|---|---|
| Original address | 0x001ceda0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ceda0 |
| Resolved name | collect_state2_entity_ids |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cee20
**Callees:** —
**Referenced globals:** 0x36c350 entity-table A; 0x36c420 entity-table B
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Like FUN_001ce890 but collects ids of state==2 entries from table-A 0x36c350 (byte8==2) into param_1 and table-B 0x36c420 (byte0x10==2) into param_2.

## Notes / uncertainty
Sibling of collect_state1 for state==2, tables A(+8) and B(+0x10) only, no flag gate, no group pass. Confirms state field is a small enum {1,2}. Clean, no aliasing ambiguity.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ceda0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
