# 0x005fb790 info_screen_delayed_overlay_sm

| field | value |
|---|---|
| Original address | 0x005fb790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb790 |
| Resolved name | info_screen_delayed_overlay_sm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb710
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005bfdd0
**Referenced globals:** +0x42b overlay id (0x12); +0x5ec list buffer; +0x16 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state

## Behavioral explanation
Timed info/list screen SM: loads a list (FUN_005b9060), advances through show/confirm, sends an op reply (FUN_005bfdd0, overlay id 0x12).

## Notes / uncertainty
4-state screen SM: load 20-entry list, 46-frame countdown, show overlay id 0x12 (builder 0x5fc610), idle. Which content list is shown unconfirmed; FUN_005b6900 idle-vs-poll untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
