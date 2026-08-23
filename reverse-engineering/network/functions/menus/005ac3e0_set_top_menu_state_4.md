# 0x005ac3e0 set_top_menu_state_4

| field | value |
|---|---|
| Original address | 0x005ac3e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac3e0 |
| Resolved name | set_top_menu_state_4 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00617270, FUN_006176a0
**Callees:** —
**Referenced globals:** 0x6c4faa(top menu state); 0x6c4fab(substate)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4faa; uRam006c4fab

## Behavioral explanation
Transition setter: forces top-level menu selector faa=4, substate fab=0.

## Notes / uncertainty
Transition setter: top_screen(0x6c4faa)=4, top_substate(0x6c4fab)=0 -> routes dispatcher to menu_state4_enter. Which UI action the callers represent unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
