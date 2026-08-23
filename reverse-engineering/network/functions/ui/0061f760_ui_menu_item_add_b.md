# 0x0061f760 ui_menu_item_add_b

| field | value |
|---|---|
| Original address | 0x0061f760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f760 |
| Resolved name | ui_menu_item_add_b |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619e00, FUN_0061fd70, FUN_00620d60, FUN_00625190, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x715312 list-A count; 0x715320 list-A ids; 0x715328 list-A type; 0x715313 list-B count; 0x715330 list-B ids; 0x715338 list-B type
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00715312; cRam00715313

## Behavioral explanation
Registers a menu/HUD element id into the same two 8-slot display lists as f680 but with type-code 2 and a different id partition.

## Notes / uncertainty
Upgraded classified->reconstructed. Twin of f680, style tag 2, ids 0..0x15: bulk->list B, only {3,4,6}->list A. Different partition than f680 confirms semantic routing. Extra ids 0x11..0x15 meaning unknown; style-2 table unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
