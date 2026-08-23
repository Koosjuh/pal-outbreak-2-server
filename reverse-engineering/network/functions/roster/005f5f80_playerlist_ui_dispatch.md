# 0x005f5f80 playerlist_ui_dispatch

| field | value |
|---|---|
| Original address | 0x005f5f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5f80 |
| Resolved name | playerlist_ui_dispatch |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005fe620
**Callees:** FUN_005f5fe0, FUN_005f60d0
**Referenced globals:** cRam00695ce0(list UI mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00695ce0

## Behavioral explanation
Player/friend-list UI dispatcher: on mode flag runs the input handler (=1) or the list rebuild (=0).

## Notes / uncertainty
Mode dispatch on 0x695ce0[0]: 1=input(FUN_005f60d0), 0=rebuild(FUN_005f5fe0). Trivial.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
