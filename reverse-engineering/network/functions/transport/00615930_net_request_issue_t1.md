# 0x00615930 net_request_issue_t1

| field | value |
|---|---|
| Original address | 0x00615930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615930 |
| Resolved name | net_request_issue_t1 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060ec60, FUN_00615a58
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250; uRam0070d240; uRam0070d248; uRam0070d24c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d240; uRam0070d248; uRam0070d24c

## Behavioral explanation
Issues resolver request type 1 with extra numeric fields (0x240/0x24c) plus the key string; submit via 616ab0(...,1).

## Notes / uncertainty
Type-1 request: key string + 3 numeric fields (+0x00/+0x08/+0x0c), submit type 1. Likely paged/ranged query; field roles unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
