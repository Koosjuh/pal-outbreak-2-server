# 0x005c2460 on_reply_member_list_filtered

| field | value |
|---|---|
| Original address | 0x005c2460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2460 |
| Resolved name | on_reply_member_list_filtered |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005c27d0, FUN_005c50a0, FUN_005c7d00
**Referenced globals:** 0x6cdbe6 raw roster; 0x6ce046 active roster; 0x6fb746/0x6fb739 active count; 0x6fb738 total; 0x70047c ready flag; 0x6cbc7c/0x6cbc84 UI status
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca890; 0x70047c; 0x6fb746

## Behavioral explanation
Member-list reply handler: fills raw roster 0x6cdbe6 (0x118), then compacts entries whose flag +0x6cdce7==1 (over 4 slots) into active roster 0x6ce046, counts them into 0x6fb746/0x6fb739, sets 0x70047c=1, stores UI status and issues two redraws (0x00 and 0x23).

## Notes / uncertainty
Full fill+pack+render: same fill as 0x5c0ae0, then packs active slots to 0x6ce046, sets counts 0x6fb746/0x6fb739, roster-ready gate 0x70047c=1, double redraw 0 then 0x23. Pack/redraw tail runs even on error status (may be artifact).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
