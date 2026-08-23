# 0x001ce740 group_register_and_fill_roster

| field | value |
|---|---|
| Original address | 0x001ce740 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce740 |
| Resolved name | group_register_and_fill_roster |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ce970
**Callees:** FUN_00109728, FUN_001cb360, FUN_001ce5b0, FUN_001ce600, FUN_001d09e0
**Referenced globals:** 0x36c310 group table; uRam0036b9c0 session/base handle
**Referenced strings:** 0x24ca70 template; 0x24ca90 template
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Creates/reuses a group slot for (param_1,param_3): builds a request via FUN_00109728+FUN_001cb360, decodes the reply roster with FUN_001d09e0, then marks slot active and records ids (short@2/8/0xc).

## Notes / uncertainty
Rewrote to full reconstruction. Idempotent group-slot register: find (ce600) else alloc (ce5b0); format key (109728, tmpls 0x24ca70/0x24ca90), issue query (cb360)->count, decode roster into slot+4 (d09e0, cap 200), stamp slot [0]=1/[2]=assoc/[8]=area/[0xc]=member. Template contents + wire-vs-local query not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce740.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
