# 0x00628760 ui_menu_list_build_op23

| field | value |
|---|---|
| Original address | 0x00628760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628760 |
| Resolved name | ui_menu_list_build_op23 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627ea0, FUN_0062d140
**Callees:** FUN_005ba570, FUN_005ba7b0, FUN_00618ba0
**Referenced globals:** 0x66a988 descriptor-ptr-table; 0x66a990/0x66a992 coord-table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds a set of UI list/widget records from a descriptor table (PTR_DAT_0066a988[selector]): allocates each via FUN_00618ba0 and fills type/coords/handler; finalizes with a title id 9 or 0x23.

## Notes / uncertainty
Descriptor-driven widget-list builder (12B descriptor stride, id<0 terminator, coord table 0x66a990). Descriptor byte+4 role and handler-u32 semantics opaque; title ids 9/0x23 are UI labels not wire ops. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
