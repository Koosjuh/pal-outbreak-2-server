# 0x005c0ae0 on_reply_member_list

| field | value |
|---|---|
| Original address | 0x005c0ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0ae0 |
| Resolved name | on_reply_member_list |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005c0dc0, FUN_005c50a0, FUN_005c7d00
**Referenced globals:** 0x6cdbe6 roster table; 0x6ca890 roster count; 0x6cbc7c/0x6cbc80/0x6cbc84 UI status; 0x6fb738 member-count field
**Referenced strings:** —
**Referenced opcodes:** 0x86
**State vars:** 0x6ca890; 0x6cbc84

## Behavioral explanation
Member-list reply handler: iterates reply entries (count at +8), copies each member's name (FUN_005c50a0) and record into roster table 0x6cdbe6 (0x118 stride, count 0x6ca890), then stores UI status and redraws.

## Notes / uncertainty
Primary roster fill: per entry encodes id->8 ASCII (FUN_005c50a0), copies name +0x10 & 0xf0 blob +0x24 into 0x6cdbe6, bumps byte count 0x6ca890, handles continuation pages, then redraw. Variable-stride TLV advance is decompiler-flattened.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
