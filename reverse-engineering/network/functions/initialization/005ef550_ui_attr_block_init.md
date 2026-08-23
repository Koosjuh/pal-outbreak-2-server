# 0x005ef550 ui_attr_block_init

| field | value |
|---|---|
| Original address | 0x005ef550 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef550 |
| Resolved name | ui_attr_block_init |
| Subsystem | initialization |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ea820, FUN_005ea880, FUN_005f0e10
**Callees:** —
**Referenced globals:** +0xdfc attr block (0x114 bytes); +0xe00; +0xe08 color/id; +0xe0c color/id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes a 0x114-byte UI attribute/style block at ctx+0xdfc and seeds defaults (+0xe08=+0xe0c=0xffffffff, +0xe00=2).

## Notes / uncertainty
memset(ctx+0xdfc,0,0x114) + sentinels +0xe08=+0xe0c=0xffffffff, +0xe00=2. Per-element style block; field roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
