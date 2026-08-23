# 0x005c3da0 dispatch_cb_table_7005e0

| field | value |
|---|---|
| Original address | 0x005c3da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3da0 |
| Resolved name | dispatch_cb_table_7005e0 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7d00
**Referenced globals:** 0x7005e0/0x7005e4 (one-shot callback table, 10 x 8)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Identical one-shot callback demux over a second 10-entry table at 0x7005e0 (stride 8), keyed on *(param1+0xc).

## Notes / uncertainty
Byte-identical twin of 0x5c3cf0 on table @0x7005e0. Partition between the two registries unestablished.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
