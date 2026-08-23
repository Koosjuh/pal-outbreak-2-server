# 0x0062d430 name_kbd_commit_step

| field | value |
|---|---|
| Original address | 0x0062d430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d430 |
| Resolved name | name_kbd_commit_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d380
**Callees:** FUN_00604860, FUN_00634ab0, FUN_00637180
**Referenced globals:** 0x6c4610 menu-selection cmp; 0x6c4618/0x6c4620 selection mask; 0x694700 buffer src
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x11 selection

## Behavioral explanation
Menu confirm-commit: compares selection (FUN_00634ab0 vs uRam006c4610/4618/4620); on match==1 copies buffer 0x694700 and zero-fills param+0x12c2 (0x19e bytes).

## Notes / uncertainty
Renamed from lobby_menu_confirm_commit. RUN/COMMIT step: kbd_input_tick each frame; on commit(=1) table_find_by_id(0x694700) + memset member scratch param_1+0x12c2 (0x19e). Lookup result discarded here; parent SM uses it. Return 1=handled/0=cancel.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
