# 0x00615f48 net_request_issue_t5

| field | value |
|---|---|
| Original address | 0x00615f48 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615f48 |
| Resolved name | net_request_issue_t5 |
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
Issues resolver request type 5: one field + one key string; submit via 616ab0(...,5).

## Notes / uncertainty
SIF-RPC stub fno 5: two strings + mode, NO session token (distinguishes from t3/t4). Verb unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615f48.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
