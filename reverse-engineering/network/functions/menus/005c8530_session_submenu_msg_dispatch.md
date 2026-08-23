# 0x005c8530 session_submenu_msg_dispatch

| field | value |
|---|---|
| Original address | 0x005c8530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8530 |
| Resolved name | session_submenu_msg_dispatch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c85d0
**Callees:** FUN_005d5b60, FUN_005d5c20
**Referenced globals:** 0x701e10 (submenu state); 0x701070+0x2e (menu/kind)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701e10

## Behavioral explanation
On sub-state 0x701e10==1, routes by iRam00701070+0x2e to a canned UI message (FUN_005d5c20 0xc/0xf) or default (FUN_005d5b60), then sets state 2.

## Notes / uncertainty
One-shot popup: when 0x701e10==1, raise msg box by kind(0x701070+0x2e): 8->0xc, 1->0xf, else default; latch to 2. Message text and kind meaning external.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
