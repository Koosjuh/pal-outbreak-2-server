# 0x005eced0 compute_center_offset

| field | value |
|---|---|
| Original address | 0x005eced0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eced0 |
| Resolved name | compute_center_offset |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ecf20, FUN_005ed0c0, FUN_005ed530, FUN_005ee010, FUN_005ee610
**Callees:** —
**Referenced globals:** iRam007012a0; +0x14 (center flag); +0x10/+0x12 (container/margin)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x14 (align)

## Behavioral explanation
Computes horizontal centering offset = (container_width - margin - content_width)/2 when center-align flag +0x14 is set.

## Notes / uncertainty
(box_right+0x10 - left_margin+0x12 - content)/2 when center flag +0x14 set; else 0. Field labels inferred from arithmetic.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eced0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
