# 0x005ff950 lobby_page_dispatcher

| field | value |
|---|---|
| Original address | 0x005ff950 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff950 |
| Resolved name | lobby_page_dispatcher |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_005ff9f0, FUN_005ffdc0, FUN_00603e40, FUN_0062ba00, FUN_0062ba70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+1 phase; param_1+0x43a pending-send flag

## Behavioral explanation
Top-level lobby/room page dispatcher: gated on busy (FUN_005aec70), routes by phase byte +1 (0=FUN_005ff9f0 room pages, 1=FUN_00603e40, 2=FUN_0062ba00/70), then runs the message/chat sender FUN_005ffdc0 when +0x43a is set.

## Notes / uncertainty
Rewrote from classified stub to full reconstruction. Busy-guarded (FUN_005aec70); phase byte at ctx+1 routes pages 0/1/2; ctx+0x43a flag triggers outbound message pump FUN_005ffdc0 (chat role inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff950.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
