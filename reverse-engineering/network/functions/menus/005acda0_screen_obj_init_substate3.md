# 0x005acda0 screen_obj_init_substate3

| field | value |
|---|---|
| Original address | 0x005acda0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acda0 |
| Resolved name | screen_obj_init_substate3 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0, FUN_00601700
**Callees:** FUN_005af120, FUN_00637180
**Referenced globals:** 0x6c45f8(sel index); 0x6c4b90
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c45f8

## Behavioral explanation
Initializes a screen-object struct: tag=1, [0xe]=3, [0xf]/[0x10]=0, stores param into 0x6c45f8.

## Notes / uncertainty
Renamed from screen_struct_init_kind3. Same ctor as substate0 but [0xe]=3 (-> branch 3 FUN_005ad680), clears [0x10], publishes param_2 to selection index 0x6c45f8. Meaning of 0x6c45f8 / branch-3 screen not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acda0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
