# 0x006345e0 open_name_entry

| field | value |
|---|---|
| Original address | 0x006345e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006345e0 |
| Resolved name | open_name_entry |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b45f0, FUN_005dc1e0, FUN_005f4be0, FUN_005f97c0, FUN_005faa60, FUN_006149f0, FUN_00625190, FUN_0062adb0, FUN_0062d3d0
**Callees:** FUN_00633350, FUN_00634160, FUN_00634470, FUN_00634540, FUN_00634880, FUN_00634890, FUN_00634970, FUN_00636190, FUN_006362e0, FUN_006371f0, FUN_00637210, FUN_00637230, FUN_00637250, FUN_00637710, FUN_00637da0
**Referenced globals:** 0x715da8 (kbd state; +0x10 layout cfg, +0x3a maxlen, +0x4c text buf, +0x2a len, +0x2f mode); 0x690b90 (layout config table); 0x715b68/0x715b70/0x715b80/0x715b90
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x3a (max len); 0x715da8+0x2f; 0x715da8+0x49c (initial name)

## Behavioral explanation
Opens/resets the name-entry widget: selects layout config (param1*0x30+0x690b90), caps max length to 0xfa (param3), seeds initial text (param4), and clears all entry/predictive/cursor state.

## Notes / uncertainty
Full text-field open/reset: layout=0x690b90+idx*0x30, maxlen cap 0xFA, optional seed, clears all cursor/predictive state. Field-index->screen mapping and layout-record layout only partial.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006345e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
