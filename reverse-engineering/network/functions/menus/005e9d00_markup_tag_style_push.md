# 0x005e9d00 markup_tag_style_push

| field | value |
|---|---|
| Original address | 0x005e9d00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d00 |
| Resolved name | markup_tag_style_push |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef220
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper invoking FUN_005ef220 (refresh).

## Notes / uncertainty
Trampoline to FUN_005ef220 style-stack push (depth +0x124 clamp 0xe, rows +0x12c/+0x169, overrides +0x2c3/+0x2d3). Open-scope tag.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
