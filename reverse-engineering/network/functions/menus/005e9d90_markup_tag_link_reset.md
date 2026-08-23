# 0x005e9d90 markup_tag_link_reset

| field | value |
|---|---|
| Original address | 0x005e9d90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9d90 |
| Resolved name | markup_tag_link_reset |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x6f0 (0x101 buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Applies arg and zeroes the 0x101-byte buffer at cfg+0x6f0 (no refresh).

## Notes / uncertainty
Same as 0x9d50 minus FUN_005ede30 finalize: flush + clear +0x6f0, no link submission. Open-vs-nonfinalizing-close ambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9d90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
