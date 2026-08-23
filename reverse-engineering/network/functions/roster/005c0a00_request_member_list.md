# 0x005c0a00 request_member_list

| field | value |
|---|---|
| Original address | 0x005c0a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0a00 |
| Resolved name | request_member_list |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa190, FUN_005fe500, FUN_005fe8d0, FUN_0062e440
**Callees:** FUN_005be0a0, FUN_005c0dc0
**Referenced globals:** 0x6cdbe6 roster table (0x118 stride); 0x6ca890 roster count; 0x6fee68 room record; 0x6febac conn
**Referenced strings:** —
**Referenced opcodes:** 0x86
**State vars:** 0x6ca890

## Behavioral explanation
Zeroes roster table 0x6cdbe6 (0x460), allocates a txn, builds op 0x86 (0dc0) and sends the member-list request for room record param_1; resets roster count 0x6ca890.

## Notes / uncertainty
op0a member-list request for room index param_1 (0x6fee68 table), clears 0x6cdbe6, callback 0x5c0ae0, resets 0x6ca890. Whether FUN_005c0dc0 emits literal 0x86 wire byte unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
