# 0x001ee430 net_result_normalize

| field | value |
|---|---|
| Original address | 0x001ee430 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee430 |
| Resolved name | net_result_normalize |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c3880, FUN_001c9850, FUN_001c9b00
**Callees:** FUN_001ee150, FUN_001ef830
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Calls FUN_001ef830 (query, writing two out-fields at +2/+3) and, on success, normalizes the *param_2 result enum to 0..10 (identity), default->7, and 0xffff->0xb.

## Notes / uncertainty
link_query(1ef830) then canonicalize buf[0] to 0..0xb: identity 0..10, 0xffff->0xb, else->7; skipped if result<0. Code meanings + out-fields (+4/+6) inferred, not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
