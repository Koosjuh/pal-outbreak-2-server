# 0x00615778 net_request_abort_cmd0f

| field | value |
|---|---|
| Original address | 0x00615778 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615778 |
| Resolved name | net_request_abort_cmd0f |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00615a58
**Callees:** FUN_00615670, FUN_00616518
**Referenced globals:** 0x70d200; 0x70d240
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Cancels/aborts an in-flight resolver request: close (616518), reset buffer, issue socket command 0xf.

## Notes / uncertainty
Abort/flush counterpart to cmd0b: close handle + channel cmd 0x0f. File also holds unrelated thunk_FUN_00616b40 (poll engine) at 0x6157d8 documented under net_request_poll.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615778.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
