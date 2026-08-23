# 0x00622d60 screen_handler_wait_reply

| field | value |
|---|---|
| Original address | 0x00622d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00622d60 |
| Resolved name | screen_handler_wait_reply |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e800, FUN_0061f0f0, FUN_0061f1a0, FUN_0061f1b0, FUN_0061f1f0, FUN_0061f470, FUN_0061f4b0, FUN_0061f680
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** substate @ struct+1; timer @ struct+4/+6

## Behavioral explanation
Screen handler that draws elements 0x37/1 and waits on link confirm/timeout (e7f0/e800), then advances or branches to an error path; returns 1/-1.

## Notes / uncertainty
Struct-family wait screen; registers overlay_frame_update, dwell then confirm/cancel -> 1/-1. Which reply it waits on not visible from handler (func_0x001b39f0 setup unread).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00622d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
