# 0x005ffb20 room_subpage_enter_timed

| field | value |
|---|---|
| Original address | 0x005ffb20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ffb20 |
| Resolved name | room_subpage_enter_timed |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff9f0
**Callees:** FUN_005c2340, FUN_005c2390
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xe/+0xf step; param_1+0x16 timer

## Behavioral explanation
Room sub-page step stub: registers render cbs 0x601580 (roster block builder) and 0x601690, then advances with a 0x10-frame timer.

## Notes / uncertainty
Self-retriggering 3-step cycle: registers render cbs 0x601580/0x601690, 16-frame wait, bumps phase +0x0e, repeats. Callback roles (0x601580 roster builder) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ffb20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
