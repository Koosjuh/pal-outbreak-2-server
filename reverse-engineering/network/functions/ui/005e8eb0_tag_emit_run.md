# 0x005e8eb0 tag_emit_run

| field | value |
|---|---|
| Original address | 0x005e8eb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8eb0 |
| Resolved name | tag_emit_run |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ee610
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler (no arg): invokes FUN_005ee610 (layout commit helper).

## Notes / uncertainty
Zero-arg tag tail-calling FUN_005ee610 = measure/word-wrap/advance current run + bbox update. Suggest rename tag_emit_run; owning token unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8eb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
