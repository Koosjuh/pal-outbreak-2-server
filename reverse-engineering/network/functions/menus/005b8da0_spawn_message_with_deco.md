# 0x005b8da0 spawn_message_with_deco

| field | value |
|---|---|
| Original address | 0x005b8da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8da0 |
| Resolved name | spawn_message_with_deco |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2260, FUN_005fb270, FUN_00604180, FUN_00607dc0, FUN_0061ded0, FUN_006293f0, FUN_006296a0, FUN_0062a8c0, FUN_0062b020, FUN_0062c3f0, FUN_0062cfd0
**Callees:** FUN_005b8cf0, FUN_005b8f60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Wrapper: spawns the message widget (FUN_005b8cf0) then adds decoration widgets via FUN_005b8f60 with mode selected by param (0x86/0x88->1, 0xaf->2, else 0).

## Notes / uncertainty
Composition wrapper: message widget + deco pair, mode 1(0x86/0x88)/2(0xaf)/0. Direct dispatch, no material uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
