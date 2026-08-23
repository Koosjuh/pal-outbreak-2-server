# 0x005ed160 advance_line_index

| field | value |
|---|---|
| Original address | 0x005ed160 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed160 |
| Resolved name | advance_line_index |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eacd0, FUN_005ebd20, FUN_005ed1f0, FUN_005f2450
**Callees:** —
**Referenced globals:** iRam007012a0; +0x188 (line/element index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x188

## Behavioral explanation
Increments the per-line/element index +0x188, saturating at 999.

## Notes / uncertainty
Increments line index +0x188, saturates at 999. Behavior fully determined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
