# 0x005ae2c0 session_seq_step3_wait

| field | value |
|---|---|
| Original address | 0x005ae2c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae2c0 |
| Resolved name | session_seq_step3_wait |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** FUN_005af310
**Referenced globals:** obj +0x993
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq step 3: waits on FUN_005af310 (ready poll) and advances cursor when nonzero.

## Notes / uncertainty
FUN_005ae130 case 3. Frame-spread barrier: advances +0x993 only when FUN_005af310() nonzero, else re-polls. Only conditional step. What the predicate checks (load vs socket) untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae2c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
