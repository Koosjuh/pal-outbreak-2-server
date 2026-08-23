# 0x005f4770 intro_timer_start

| field | value |
|---|---|
| Original address | 0x005f4770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4770 |
| Resolved name | intro_timer_start |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3f50
**Callees:** —
**Referenced globals:** uRam00701f30(active); uRam00701f28(counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00701f30; uRam00701f28

## Behavioral explanation
Starts the intro/attract frame timer.

## Notes / uncertainty
Arms attract/intro timer (uRam00701f30=1, counter=1) via 003adb70. Pairs with intro_timer_check. Timer unit unknown. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
