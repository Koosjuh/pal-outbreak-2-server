# 0x00615e20 net_request_issue_t3

| field | value |
|---|---|
| Original address | 0x00615e20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615e20 |
| Resolved name | net_request_issue_t3 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250; 0x70d350; uRam0070d244(=0x654200); uRam0070d248
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d244; uRam0070d248

## Behavioral explanation
Issues resolver request type 3: two strings + mode word; submit via 616ab0(...,3).

## Notes / uncertainty
SIF-RPC stub fno 3: str1@+0x10, mode@+0x08, str2@+0x110, session token@+0x04. Async. Marshalling mechanics High; domain verb behind fno unconfirmed (no callers).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615e20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
