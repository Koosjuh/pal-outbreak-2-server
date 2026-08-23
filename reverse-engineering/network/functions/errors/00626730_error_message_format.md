# 0x00626730 error_message_format

| field | value |
|---|---|
| Original address | 0x00626730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00626730 |
| Resolved name | error_message_format |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x365bb4 code-table; 0x365bb0 count; 0x66a810 msg-base-table; 0x34359d lang-idx; 0x6fc5e8 out-textbuf; 0x66a848 fmt
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; uRam0086f7e0 result; uRam007152ea idx

## Behavioral explanation
On dispatch code 0x27 selects a message-string id from an incoming code (+4) — maps 0x11/0x13/other to 0x331/0x32c/0x332 etc — and formats it into text buffer 0x6fc5e8.

## Notes / uncertainty
Resolves net/lobby status code (param_2+4) to localized string: searches code table 0x365bb4[0x365bb0], else synthesizes via language table 0x66a810[0x34359d] into 0x6fc5e8. Codes 0x11/0x13/<0x19 map to string ids 0x331/0x32c/0x334+code. Table-dispatched (no resolved callers); string ids not textualized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00626730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
