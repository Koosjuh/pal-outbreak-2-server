# 0x00615ea8 net_request_issue_t4

| field | value |
|---|---|
| Original address | 0x00615ea8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615ea8 |
| Resolved name | net_request_issue_t4 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250; 0x70d350; 0x70d450; uRam0070d244; uRam0070d248
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d244; uRam0070d248

## Behavioral explanation
Issues resolver request type 4: three strings (0x70d250/0x70d350/0x70d450) + mode word; submit via 616ab0(...,4).

## Notes / uncertainty
SIF-RPC stub fno 4: three strings (+0x10/+0x110/+0x210) + mode + token. Widest shape; verb unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615ea8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
