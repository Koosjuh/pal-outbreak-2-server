# 0x005db130 ui_spawn_vscrollbar

| field | value |
|---|---|
| Original address | 0x005db130 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005db130 |
| Resolved name | ui_spawn_vscrollbar |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e80: UI state flag; iRam00701070+0x20/0x1a: geometry; LAB_005db220
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e80

## Behavioral explanation
UI widget factory: allocates a vertical-scrollbar node positioned from viewport margins, installs draw callback FUN_005db300; sets flag 0x68e80=2.

## Notes / uncertainty
Factory (pool 2): right-aligned scrollbar node (x=624-margin, 16x380), draw cb FUN_005db300, flag 0x68e80=2. Writes real float geometry. Node+0x30 role unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005db130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
