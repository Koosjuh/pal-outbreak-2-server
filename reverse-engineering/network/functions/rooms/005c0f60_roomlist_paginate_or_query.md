# 0x005c0f60 roomlist_paginate_or_query

| field | value |
|---|---|
| Original address | 0x005c0f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0f60 |
| Resolved name | roomlist_paginate_or_query |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe500, FUN_005fe8d0, FUN_005fec30, FUN_005fede0, FUN_0062e8e0
**Callees:** FUN_005bf230, FUN_005c5f10
**Referenced globals:** 0x6ff2b0 host flag; 0x6fb748 room-list page count; 0x6febec room total; 0x6febfc; 0x6cbc84 status
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ff2b0

## Behavioral explanation
Branches on host flag 0x6ff2b0: if not host, records param_2 and calls FUN_005c5f10; if host, clears status and computes room-list page count 0x6fb748 = 0x6febec/0x1e (30 rooms/page) then FUN_005bf230.

## Notes / uncertainty
Host/joiner split on 0x6ff2b0: joiner sends reliable app op 0x0a query (via FUN_005c5f10) stashing cb@0x6febfc; host clears status and computes pages=total/30 then fires cb via FUN_005bf230. Grounded via callees. Joiner reply-cb identity not fully traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0f60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
