# 0x005ace00 screen_substate_dispatch_A

| field | value |
|---|---|
| Original address | 0x005ace00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ace00 |
| Resolved name | screen_substate_dispatch_A |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005acea0, FUN_005ad030, FUN_005ad530, FUN_005ad680, FUN_005af1a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-screen dispatcher: on screen-object field +0xe (0..3) routes to ad680/ad530/ad030/acea0, then re-arms input (5af1a0). thunk at 0x5acdf0 is identical and is the one acab0 calls.

## Notes / uncertainty
Sub-screen dispatcher: switch on obj[+0xe] 3->ad680/2->ad530/1->ad030/0->acea0, then input re-arm 5af1a0. Closes init(acd60/acda0)->dispatch loop. Byte-identical thunk @0x5acdf0 is the copy acab0 calls; direct fn has no listed caller. Concrete sub-screens not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ace00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
