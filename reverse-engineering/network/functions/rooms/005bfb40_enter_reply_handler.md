# 0x005bfb40 enter_reply_handler

| field | value |
|---|---|
| Original address | 0x005bfb40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfb40 |
| Resolved name | enter_reply_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf180, FUN_005c1f30, FUN_005c4dc0, FUN_005c7d00, FUN_005c7e30
**Referenced globals:** 0x6cbc84 status; 0x6cbc80 result word; 0x6cbc7e const 2; 0x6cbc7c selector
**Referenced strings:** ' (0x27) error tag
**Referenced opcodes:** —
**State vars:** 0x6cbc84

## Behavioral explanation
Reply handler for the enter txn: on ok clears status, commits channel-0 (FUN_005bf180), refreshes room state (FUN_005c4dc0), stores result word 0x6cbc80; on 0x27 error path sets 0x6cbc84=0xff and FUN_005c7e30(5); then re-arms UI (FUN_005bdfe0).

## Notes / uncertainty
op06 ENTER reply: ok->commit channel-0 (FUN_005bf180(0))+room refresh FUN_005c4dc0+result 0x6cbc80; 0x27->status 0xff+error screen 5. Always 0x6cbc7e=2, op6e selector 0x6cbc7c, refresh. Notably does NOT set ownership lock 0x6ff2b1 (that's 0x5c3490).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfb40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
