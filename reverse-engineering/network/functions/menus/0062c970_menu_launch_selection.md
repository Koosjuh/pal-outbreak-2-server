# 0x0062c970 menu_launch_selection

| field | value |
|---|---|
| Original address | 0x0062c970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c970 |
| Resolved name | menu_launch_selection |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062c350
**Callees:** FUN_005f4b70, FUN_005f7570, FUN_005f8b50
**Referenced globals:** +0x10ba mode; +0x10bc param
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
On timer expiry dispatches into a downstream scene/mode based on the selection fields +0x10ba/+0x10bc (FUN_005f4b70/5f7570/5f8b50).

## Notes / uncertainty
Terminal scene-launch handler (child of c350): delay timer +4 then teardown FUN_005f4b70 and dispatch on launch mode +0x10ba (0->default 5f7570, 1->specific 5f8b50 with param +0x10bc, >=2->normalize to 0). Likely hands off toward the enter/room flow; concrete scenes not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
