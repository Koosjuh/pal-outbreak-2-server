# 0x005ae1e0 session_seq_step0_reset

| field | value |
|---|---|
| Original address | 0x005ae1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae1e0 |
| Resolved name | session_seq_step0_reset |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** —
**Referenced globals:** obj +0x993/+0x45a/+0x44d; 0x701e10
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq step 0: clears input/redraw flags (+0x45a,+0x44d,0x701e10) and advances the +0x993 cursor.

## Notes / uncertainty
FUN_005ae130 case 0. Clears +0x45a & 0x701e10, sets active +0x44d=1, advances step cursor +0x993. Field names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
