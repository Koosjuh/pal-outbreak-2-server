# 0x00615a58 net_records_enumerate

| field | value |
|---|---|
| Original address | 0x00615a58 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615a58 |
| Resolved name | net_records_enumerate |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615778, FUN_006157e8, FUN_006158c8, FUN_00615930, FUN_006159c0, FUN_00616b40
**Referenced globals:** 0x70d200/0x70d240 (request/result)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Orchestrates a multi-record async query: issues count/type-1/type-2 requests in loops, allocates a 0x240-stride record array, matches a key (109d70) and copies matched records — a list fetch/lookup over the resolver API.

## Notes / uncertainty
Two-stage directory resolve over IOP RPC fno 0/1/2 (query-begin/fetch-page/fetch-detail); 0x240-stride records, key@+0x108, secondary key@chosen1+8, duplicate-match=-12. Mechanism fully recovered; domain meaning of listType 1/2 vs 0 and the two keys unconfirmed, no callers in slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615a58.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
