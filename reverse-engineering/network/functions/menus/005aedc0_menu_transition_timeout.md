# 0x005aedc0 menu_transition_timeout

| field | value |
|---|---|
| Original address | 0x005aedc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aedc0 |
| Resolved name | menu_transition_timeout |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005f6970, FUN_00608670
**Referenced globals:** 0x701e10 cRam00701e10 done latch; 0x6c4610 iRam006c4610; 0x6c4628 cRam006c4628 pad-held latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x558/+0x55c/+0x560 timers; +0x56a input flag

## Behavioral explanation
Per-frame menu transition/timeout driver: decrements timers (+0x558/+0x55c/+0x560), on input flags (+0x56a) or expiry sets the done latch cRam00701e10 and fires FUN_005f6970(n) to trigger the next screen.

## Notes / uncertainty
Per-frame auto-advance/timeout: decrements +0x558; display-only mode latches g_screen_done 0x701e10, interactive mode calls FUN_005f6970(reason 3/5/6/7). Skipped for kind 6. func_0x001ee360 = event-pending poll (inferred, maybe network); reason->target-screen mapping not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aedc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
