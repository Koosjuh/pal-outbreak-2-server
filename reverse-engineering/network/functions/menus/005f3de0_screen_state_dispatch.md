# 0x005f3de0 screen_state_dispatch

| field | value |
|---|---|
| Original address | 0x005f3de0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3de0 |
| Resolved name | screen_state_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f3e30, FUN_005f3f50
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x08 (screen phase)

## Behavioral explanation
Screen-object dispatcher: on state byte+8 calls the tick (=1) or init (=0) handler.

## Notes / uncertainty
Scene pump: phase byte +0x08 => 1 tick(005f3f50)/0 init(005f3e30); init bumps phase 0->1 so init runs once. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3de0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
