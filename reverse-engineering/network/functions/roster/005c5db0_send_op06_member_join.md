# 0x005c5db0 send_op06_member_join

| field | value |
|---|---|
| Original address | 0x005c5db0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5db0 |
| Resolved name | send_op06_member_join |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** —

## Behavioral explanation
Builds and sends the reliable app-opcode 0x06 member-JOIN/enter packet with a 0x22-byte member record to the target.

## Notes / uncertainty
op10-relay of inner op 0x06 with 0x22-byte member-join record {srcIdx,0,name[0x10],field[0x10]}; SM drives a recipient x source matrix announcing each member to every other. Field split within the 0x22 body read from SM copy-sources, wire-unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5db0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
