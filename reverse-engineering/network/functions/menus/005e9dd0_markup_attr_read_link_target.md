# 0x005e9dd0 markup_attr_read_link_target

| field | value |
|---|---|
| Original address | 0x005e9dd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9dd0 |
| Resolved name | markup_attr_read_link_target |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x6f0 (0x100 str)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field handler: copies a 0x100-byte string into cfg+0x6f0.

## Notes / uncertainty
Reads ="..." attr into link/href buffer +0x6f0 (0x100). URL vs action-id depends on FUN_005d9290.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9dd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
