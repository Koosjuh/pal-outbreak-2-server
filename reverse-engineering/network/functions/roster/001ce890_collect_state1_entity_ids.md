# 0x001ce890 collect_state1_entity_ids

| field | value |
|---|---|
| Original address | 0x001ce890 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce890 |
| Resolved name | collect_state1_entity_ids |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce970
**Callees:** —
**Referenced globals:** 0x36c350 entity-table A; 0x36c420 entity-table B (16 x 0x14); 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Gathers ids of state==1 entries: from table-A 0x36c350 (byte8==1) into param_1, table-B 0x36c420 (byte0x10==1) into param_2, and all 4 group slots (short@8/@0xc) into param_3.

## Notes / uncertainty
Snapshot of state==1 population in one 16-pass: table-A ids (active&&state1&&flags&4)->p1, table-B ids->p2, group id pairs (first 4)->p3. OPEN: table-B branch tests table-A's flag byte (pcVar4[3]) - either intentional cross-table gate or Ghidra aliasing artifact; flagged for verification.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
