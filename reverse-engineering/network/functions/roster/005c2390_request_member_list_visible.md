# 0x005c2390 request_member_list_visible

| field | value |
|---|---|
| Original address | 0x005c2390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2390 |
| Resolved name | request_member_list_visible |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ffb20
**Callees:** FUN_005be0a0, FUN_005c27d0
**Referenced globals:** 0x6ce046 filtered roster table; 0x6cdbe6 roster table; 0x6ca890 count; 0x86f840 room record ptr; 0x6febac conn
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca890

## Behavioral explanation
Zeroes two roster tables (0x6ce046 and 0x6cdbe6, 0x460 each), allocates a txn, builds the member-list op (2760) and sends it (func_0x001de0c0, arg record uRam0086f840); resets roster count 0x6ca890.

## Notes / uncertainty
Fuller member-list request: clears both 0x6ce046 & 0x6cdbe6, room from global 0x86f840, callback 0x5c2460 (packs visible + sets 0x70047c gate). Source of global room ptr vs indexed table unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
