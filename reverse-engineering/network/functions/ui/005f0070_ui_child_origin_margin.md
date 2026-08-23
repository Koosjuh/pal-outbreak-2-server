# 0x005f0070 ui_child_origin_margin

| field | value |
|---|---|
| Original address | 0x005f0070 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0070 |
| Resolved name | ui_child_origin_margin |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb250
**Callees:** —
**Referenced globals:** node+0x28/+0x2a origin; node+0x2c/+0x2e offset; node+0x32 margin
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets a child node's origin (+0x28/+0x2a) = parent margin(+0x32) + parent pos + parent offset, and zeroes its scroll offset.

## Notes / uncertainty
Pure geometry: child origin = parent origin+flow inset by margin(+0x32); zeroes flow cursors. Margin/pad naming by analogy to f0300.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
