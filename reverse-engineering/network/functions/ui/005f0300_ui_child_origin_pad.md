# 0x005f0300 ui_child_origin_pad

| field | value |
|---|---|
| Original address | 0x005f0300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0300 |
| Resolved name | ui_child_origin_pad |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb7d0
**Callees:** —
**Referenced globals:** node+0x28/+0x2a origin; node+0x30 padding
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets child origin (+0x28/+0x2a) using parent padding(+0x30) + parent pos + offset, zeroing scroll offset (padding-variant of f0070).

## Notes / uncertainty
Padding variant of f0070 (inset by +0x30). Byte-identical except inset field.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
