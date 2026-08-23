# 0x006159c0 net_request_issue_t2

| field | value |
|---|---|
| Original address | 0x006159c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006159c0 |
| Resolved name | net_request_issue_t2 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060ed40, FUN_0060eff0, FUN_00615a58
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250; 0x70d350; uRam0070d244(=0x654200); uRam0070d248; uRam0070d24c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d244; uRam0070d248

## Behavioral explanation
Issues resolver request type 2: two key strings (0x70d250,0x70d350) plus mode word 0x654200; submit via 616ab0(...,2).

## Notes / uncertainty
Type-2 request: 2 key strings (0x70d250/0x70d350) + id + mode(0x654200) + field, submit type 2. Producer/consumer link to net_set_request_mode confirmed; query class + string slot sizes (0x100) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006159c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
