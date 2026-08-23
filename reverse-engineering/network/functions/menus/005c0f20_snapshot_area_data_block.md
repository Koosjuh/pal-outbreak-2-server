# 0x005c0f20 snapshot_area_data_block

| field | value |
|---|---|
| Original address | 0x005c0f20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0f20 |
| Resolved name | snapshot_area_data_block |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f9280, FUN_005fa190, FUN_005fe8d0, FUN_0062de90
**Callees:** —
**Referenced globals:** 0x6d2294 large data block (~168KB)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a large ~0x294a3-byte block from 0x6d2294 into caller buffer param_2.

## Notes / uncertainty
Bulk copy of 0x294a3-byte (169KB) area/scenario blob at 0x6d2294 into caller buffer; param_1 unused. Internal blob structure unmapped; backup-vs-transmit purpose unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0f20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
