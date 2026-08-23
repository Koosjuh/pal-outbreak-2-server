# 0x005dc3b0 ui_spawn_softkbd_widget

| field | value |
|---|---|
| Original address | 0x005dc3b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dc3b0 |
| Resolved name | ui_spawn_softkbd_widget |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068+0x68e84: submenu flag; LAB_005dc450
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e84

## Behavioral explanation
UI widget factory: allocates the text-entry widget node, installs draw/commit callback FUN_005dc4b0; sets submenu flag 0x68e84=2.

## Notes / uncertainty
Factory kind-4 text-entry host, seeds phase(+6)=1 armed, flag 0x68e84=2, draw/commit cb FUN_005dc4b0. 0x68e84 value semantics (1 vs 2) partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dc3b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
