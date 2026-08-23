# 0x00607f70 build_menu_node_list

| field | value |
|---|---|
| Original address | 0x00607f70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607f70 |
| Resolved name | build_menu_node_list |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607ac0
**Callees:** FUN_005ba570, FUN_005ba7b0, FUN_00618ba0
**Referenced globals:** 0x0064a0a0 menu-config-table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a static config table at 0x64a0a0 (stride 6 shorts, negative-terminated) allocating a node (FUN_00618ba0(0x1f)) per entry and initializing its id/payload fields.

## Notes / uncertainty
Data-driven fixed menu builder from negative-terminated config table 0x64a0a0 (stride 0xc: id@+0, cb@+8); pool-exhaustion aborts without commit. Middle table bytes and 0x1f alloc arg role uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607f70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
