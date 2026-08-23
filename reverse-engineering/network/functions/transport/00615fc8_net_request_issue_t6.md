# 0x00615fc8 net_request_issue_t6

| field | value |
|---|---|
| Original address | 0x00615fc8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615fc8 |
| Resolved name | net_request_issue_t6 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250; uRam0070d248
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d248

## Behavioral explanation
Issues resolver request type 6: one field + one key string; submit via 616ab0(...,6).

## Notes / uncertainty
SIF-RPC stub fno 6: same tokenless two-string+mode shape as t5, only fno differs. Verb unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615fc8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
