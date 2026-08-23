# 0x005d6710 list_node_free

| field | value |
|---|---|
| Original address | 0x005d6710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6710 |
| Resolved name | list_node_free |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8340
**Callees:** FUN_005d6680
**Referenced globals:** 0x701068+0x4f694 list head
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Removes a node from the 0x4f694 list and clears its extended fields (0x10c..0x125).

## Notes / uncertainty
Wrapper: 0x6680 on global list head (iRam00701068+0x4f694) then clears extended header 0x10c..0x125 (type@0x10c). Semantics of words +0x110..+0x120 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
