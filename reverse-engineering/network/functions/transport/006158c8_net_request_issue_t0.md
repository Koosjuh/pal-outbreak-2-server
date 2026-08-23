# 0x006158c8 net_request_issue_t0

| field | value |
|---|---|
| Original address | 0x006158c8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006158c8 |
| Resolved name | net_request_issue_t0 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060eba0, FUN_00615a58
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250 (key str); uRam0070d248; 0x70d200/0x70d240
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d248

## Behavioral explanation
Issues resolver request type 0: reset buffer, copy one key string to 0x70d250, set field 0x248, submit via 616ab0(...,0).

## Notes / uncertainty
Type-0 request: 1 key string (0x70d250) + id (0x70d248), submit 616ab0 type 0. Query semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006158c8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
