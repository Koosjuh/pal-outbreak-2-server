# 0x005e9c70 menu_row_append_item

| field | value |
|---|---|
| Original address | 0x005e9c70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9c70 |
| Resolved name | menu_row_append_item |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70, FUN_005ef200
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Runs FUN_005ef200 then applies arg via FUN_005eef70.

## Notes / uncertainty
Append item to menu: FUN_005ef200 (opaque) + FUN_005eef70 (appends into cfg+0x1540[cfg+0x188], mode split on cfg+0xd892). Item record layout & ef200 uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9c70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
