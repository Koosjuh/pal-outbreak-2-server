# 0x005bcfd0 session_open_result_handler

| field | value |
|---|---|
| Original address | 0x005bcfd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bcfd0 |
| Resolved name | session_open_result_handler |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bc860, FUN_005bdf90, FUN_005c7e30, FUN_005c7f20
**Referenced globals:** 0x6fc5e8 (0x300 error/message buffer); 0x365df8 (error text); 0x639e68 (error-string table); 0x6febac (conn handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-open result/error handler: on success (byte0==0) either arms the connect-established callback (FUN_005bc860 + func_0x001de648 ->0x5bcee0) or advances to screen 2; on failure maps the negative/positive result code (0x3a..0x3f, 1..8) to an error message index (639e68 table) and error screen (FUN_005c7e30 8/9) then dispatches screen 2.

## Notes / uncertainty
Session-open reply handler. status==0 -> arm established cb 0x5bcee0 (link pending) or screen 2; else demux signed code into (fatal? screen9:screen8, msgIdx) and format 0x639e68[idx] into error buf 0x6fc5e8. func_0x001bf030 (link-pending test) meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bcfd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
