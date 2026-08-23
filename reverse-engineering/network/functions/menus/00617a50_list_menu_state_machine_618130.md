# 0x00617a50 list_menu_state_machine_618130

| field | value |
|---|---|
| Original address | 0x00617a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617a50 |
| Resolved name | list_menu_state_machine_618130 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_005af300, FUN_005b2470, FUN_005b68e0, FUN_005b6900, FUN_005c0e30, FUN_005f6970
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf minor-state (0..4); +0x997 choice result; +0x42b=0x1c screen-id; +0x16 countdown

## Behavioral explanation
Per-tick state machine (minor +0xf 0..4) for a scene driven by table 0x618130: opens a UI list (FUN_005c0e30), waits, and on a stored choice at +0x997 either resets the object or invokes FUN_005f6970.

## Notes / uncertainty
Renamed. Idle-gated (FUN_005aec70) list-menu SM (obj+0xf 0-4) driving table 0x618130, screen-id 0x1c; choice obj+0x997: 1=exit(reset type-1), 2=confirm(FUN_005f6970). State1->2/4 transition driven by external select callback (not in batch).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
