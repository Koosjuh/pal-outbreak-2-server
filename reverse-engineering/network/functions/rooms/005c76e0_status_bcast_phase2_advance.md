# 0x005c76e0 status_bcast_phase2_advance

| field | value |
|---|---|
| Original address | 0x005c76e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c76e0 |
| Resolved name | status_bcast_phase2_advance |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c7540
**Callees:** FUN_005bdfe0
**Referenced globals:** 0x6cbc7e/0x6cbc84 (redraw); 0x6d2158 (count); 0x6cf286<-0x6ff2a6
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** context+0x25 (ack); context+0xc (page)

## Behavioral explanation
Phase-2 loop advance: steps page; at page>=4 finalizes, sets count=1 and pokes a different redraw (FUN_005bdfe0(0x14)), storing 0x6ff2a6->0x6cf286.

## Notes / uncertainty
Phase-2 finalizer: after 4 pages deactivates task (ctx+0x24=0), sets room_mode 0x10, member count 0x6d2158=1 (self), commits 0x6ff2a6->0x6cf286, fires event 0x14. Directly relevant to G12 create-room roster/count. Whether count=1 is hard constant vs placeholder unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c76e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
