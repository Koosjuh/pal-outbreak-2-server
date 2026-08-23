# 0x005ae3c0 session_seq_reset

| field | value |
|---|---|
| Original address | 0x005ae3c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae3c0 |
| Resolved name | session_seq_reset |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** —
**Referenced globals:** obj +0x993/+0x45a/+0x44d
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq final: resets +0x993=0 and toggles redraw/input flags (+0x45a=1,+0x44d=0).

## Notes / uncertainty
Leaf: ctx+0x993 seq cursor=0, +0x45a redraw=1, +0x44d input-lock=0. Field polarity (redraw vs input) inferred from siblings, not runtime-proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae3c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
