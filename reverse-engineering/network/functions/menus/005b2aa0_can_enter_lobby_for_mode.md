# 0x005b2aa0 can_enter_lobby_for_mode

| field | value |
|---|---|
| Original address | 0x005b2aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2aa0 |
| Resolved name | can_enter_lobby_for_mode |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2bc0
**Callees:** —
**Referenced globals:** 0x874f35 cRam00874f35 lobby/room mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x874f35

## Behavioral explanation
Transition predicate: returns 1 if the requested entry sub-state (0-4) is permitted for the current mode 0x874f35.

## Notes / uncertainty
Pure allow-table predicate over lobby mode cRam00874f35 (0..3) for entry level param_1 (0..4); level 0 always OK, level 1 strictest (mode 0 only). Boolean logic exact; per-value domain meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2aa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
