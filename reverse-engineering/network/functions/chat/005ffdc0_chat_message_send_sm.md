# 0x005ffdc0 chat_message_send_sm

| field | value |
|---|---|
| Original address | 0x005ffdc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ffdc0 |
| Resolved name | chat_message_send_sm |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff950
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005c4d20
**Referenced globals:** iRam003435d4+0xc942c member slots; +0x8000 send scratch (len 0x20 @+0x8008)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x12 send-step; param_1+0x4a3 target slot

## Behavioral explanation
Outbound chat/message state-machine (cases 0-0x0b): finds an active member slot, accumulates the message body in 0x20-byte chunks (+0x24 length), and when <0x800 flushes it through FUN_005c4d20 (encrypt+send, render cb 0x6001d0).

## Notes / uncertainty
Outbound chat fragmentation SM: streams a member's body in 0x20-byte chunks into a 44-byte scratch record {marker,has_more,chunk_len,data[0x20]} via FUN_005c4d20, cap 0x800. Slot table 4x0x830 @ iRam003435d4+0xc942c. UNCERTAIN: case-2 selects slot by id_cmp!=0 while case-3 re-locates by id_cmp==0 (two id fields slot+4 vs slot+0x14); target-id match direction inferred, no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ffdc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
