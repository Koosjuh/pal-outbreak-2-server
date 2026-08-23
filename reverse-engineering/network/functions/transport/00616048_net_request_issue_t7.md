# 0x00616048 net_request_issue_t7

| field | value |
|---|---|
| Original address | 0x00616048 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616048 |
| Resolved name | net_request_issue_t7 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Issues resolver request type 7: key string only; submit via 616ab0(...,7).

## Notes / uncertainty
SIF-RPC stub fno 7: single string@+0x10, no mode/token (minimal shape). Verb unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616048.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
