# 0x0061f680 ui_menu_item_add_a

| field | value |
|---|---|
| Original address | 0x0061f680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f680 |
| Resolved name | ui_menu_item_add_a |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f9f0, FUN_0061fd70, FUN_00620d60, FUN_00622d60, FUN_00623be0, FUN_00624850, FUN_00625190, FUN_00625670, FUN_00625ea0, FUN_00626900, FUN_00627540
**Callees:** —
**Referenced globals:** 0x715312 list-A count; 0x715320 list-A ids; 0x715328 list-A type; 0x715313 list-B count; 0x715330 list-B ids; 0x715338 list-B type
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00715312; cRam00715313

## Behavioral explanation
Registers a menu/HUD element id into one of two 8-slot display lists (partitioned by id range), tagging entries with type-code 1.

## Notes / uncertainty
Upgraded classified->reconstructed. Peer of f4b0/f600/f760: routes id 0..0x10 into list A {0,1,2,0xd,0xe} vs list B {rest}, style tag 1, cap 8, no default. A/B partition is category-based not numeric. Style-1 table + list-A/B on-screen identity unresolved w/o draw trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
