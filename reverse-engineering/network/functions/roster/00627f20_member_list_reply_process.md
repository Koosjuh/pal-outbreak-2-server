# 0x00627f20 member_list_reply_process

| field | value |
|---|---|
| Original address | 0x00627f20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627f20 |
| Resolved name | member_list_reply_process |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** FUN_005b1190, FUN_005b14b0, FUN_00627a80, FUN_00627b00
**Referenced globals:** 0x715512 slot-timer; 0x694710 master-id; 0x_param+0xefb name-copy
**Referenced strings:** —
**Referenced opcodes:** 0x23
**State vars:** —

## Behavioral explanation
Processes the op-0x23 member-list reply: iterates returned entries (+0xc base, +8 count), marks/selects roster slots, and advances or re-queries via the L1 send-queue guards FUN_005b14b0.

## Notes / uncertainty
Case-1 REPLY: yields on not-ready slot timer 0x715512[idx]<1, clamps 7-row window, three FUN_005b14b0(0x10/0x200/0x20) send-guards fork to advance/refresh(sel=3)/done; copies name/id from 0x694700/0x694710 to room+0xefb/+0xf0b. Send-mask meanings unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627f20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
