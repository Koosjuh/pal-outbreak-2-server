# 0x005bfe90 leave_reply_handler

| field | value |
|---|---|
| Original address | 0x005bfe90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfe90 |
| Resolved name | leave_reply_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf130, FUN_005c2080, FUN_005c7d00
**Referenced globals:** 0x6cbc84 status; 0x6cbc80 result word; 0x6cbc7e const 2; 0x6cbc7c selector
**Referenced strings:** ' (0x27) error tag
**Referenced opcodes:** —
**State vars:** 0x6cbc84

## Behavioral explanation
Reply handler for FUN_005bfe00: on ok clears status, clears channel-1 (FUN_005bf130), stores result word 0x6cbc80; on 0x27 sets error; re-arms UI (FUN_005bdfe0).

## Notes / uncertainty
op07 LEAVE reply: mirror of enter but clears channel-1 (FUN_005bf130(1)) on ok and no error screen on 0x27; latches result 0x6cbc80, 0x6cbc7e=2, op70 selector 0x6cbc7c, refresh.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfe90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
