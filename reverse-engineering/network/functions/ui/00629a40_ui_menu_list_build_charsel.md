# 0x00629a40 ui_menu_list_build_charsel

| field | value |
|---|---|
| Original address | 0x00629a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629a40 |
| Resolved name | ui_menu_list_build_charsel |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628f00, FUN_006290e0
**Callees:** FUN_005ba570, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x66ac90 descriptor-table; 0x66ac30/0x66ac32 coord-table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the character-select UI widget records from descriptor table PTR_DAT_0066ac90[param] (alloc via FUN_00618ba0, fill type/coords/handler), finalized with FUN_005ba570.

## Notes / uncertainty
Charsel twin of 0x628760: clears list then builds from 0x66ac90 descriptors (alloc tag 0xd, coord 0x66ac30). FUN_005ba570 title-id not captured in decompile.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
