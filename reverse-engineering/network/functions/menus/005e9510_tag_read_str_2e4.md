# 0x005e9510 tag_read_str_2e4

| field | value |
|---|---|
| Original address | 0x005e9510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9510 |
| Resolved name | tag_read_str_2e4 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x2e4 (0x100 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x100-byte string into cfg+0x2e4.

## Notes / uncertainty
256B string ctx+0x2e4, head of 0x40c block-state region cleared by FUN_005ef1a0. Upgraded Medium->High. Exact block-string role (text/name/target) unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
