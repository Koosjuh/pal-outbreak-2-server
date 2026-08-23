# 0x005c21c0 on_reply_op_d3

| field | value |
|---|---|
| Original address | 0x005c21c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c21c0 |
| Resolved name | on_reply_op_d3 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005c2250, FUN_005c7d00, FUN_005c7e30
**Referenced globals:** 0x6cbc84 status; 0x6cbc7c/0x6cbc7e/0x6cbc80 UI reply fields
**Referenced strings:** —
**Referenced opcodes:** 0xd3
**State vars:** 0x6cbc84

## Behavioral explanation
Reply handler for op 0xd3: on success clears status 0x6cbc84=0; on error 0x27 sets 0xff and calls FUN_005c7e30(3); stores UI reply fields (status=result of 2250) and redraws.

## Notes / uncertainty
Reply cb for transport op 0xd3: reply[0]==0 ok (status 0x6cbc84=0), ==0x27 err (0xFF + error dialog FUN_005c7e30(3)); stores reply[+0xc]->0x6cbc80, kind 0x6cbc7e=2, arms next req via FUN_005c2250 (registry 0x7018d0/op0xd3), redraw FUN_005bdfe0. Domain of op 0xd3 unknown (transport-level req id).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c21c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
