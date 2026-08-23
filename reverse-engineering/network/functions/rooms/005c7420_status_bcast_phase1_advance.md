# 0x005c7420 status_bcast_phase1_advance

| field | value |
|---|---|
| Original address | 0x005c7420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7420 |
| Resolved name | status_bcast_phase1_advance |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c72d0
**Callees:** FUN_005bdfe0, FUN_005bf1e0
**Referenced globals:** 0x6ce5e0 (member status, 0x144 stride); 0x7006b0<-0x7006c0 (scratch copy); 0x6d2158 (count); 0x6cbc7e/0x6cbc84 (redraw); 0x6ff2a4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** context+0xc (page); context+0x25 (ack)

## Behavioral explanation
Phase-1 loop advance: on ack (+0x25) steps page (+0xc); at page>=4 commits member status into table, copies scratch table, and pokes redraw (FUN_005bdfe0(0xf)).

## Notes / uncertainty
4-page ack loop; on completion commits acc 0x6ff2a4 to member-status table 0x6ce5e0[idx*0x144], sets room_mode 0x6cbc7e=0x10, 0x6d2158=idx+1, fires event 0xf. FUN_005bf1e0(0) treated as 1-based local member idx (inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
