# 0x005e9b20 room_apply_by_count

| field | value |
|---|---|
| Original address | 0x005e9b20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9b20 |
| Resolved name | room_apply_by_count |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ed1f0, FUN_005ef0e0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x8f4 (room count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x8f4

## Behavioral explanation
Applies arg; calls FUN_005ed1f0(0) if count cfg+0x8f4==0 else FUN_005ed1f0(1).

## Notes / uncertainty
Close handler: layout_list_item_bullet(0) if count(0x8f4)==0 else (1). The empty-vs-occupied room row styling decision — relevant to create-room 1/0P. Visual diff of bullet modes 0/1 not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9b20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
