# 0x005ae3a0 session_seq_step5_advance

| field | value |
|---|---|
| Original address | 0x005ae3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae3a0 |
| Resolved name | session_seq_step5_advance |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** —
**Referenced globals:** obj +0x993
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq step 5: no-op body that just advances the +0x993 cursor.

## Notes / uncertainty
FUN_005ae130 case 5. Pure pad: advances +0x993 only, one-frame gap between step4(0x5ae310) and step6(0x5ae3c0). Behaviorally inert.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae3a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
