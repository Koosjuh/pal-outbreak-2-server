# 0x005c4af0 send_chat_message_and_echo

| field | value |
|---|---|
| Original address | 0x005c4af0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4af0 |
| Resolved name | send_chat_message_and_echo |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4be0
**Callees:** FUN_005bdf90, FUN_005c4bd0
**Referenced globals:** 0x6fc05a msg-buf; 0x6fc17e sender-byte; 0x6fc06a name-copy; 0x6fc07e text; 0x6febb8 local-username
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Assembles and emits a chat/DATA message: clears 0x6fc05a buffer, stamps sender-name len, copies name+text, then queues UI event 5.

## Notes / uncertainty
Chat send entry (from UI 0x5f4be0): calls build_send_chat_datagram (op0f wire), then builds local echo block 0x6fc05a (type,name,text) and posts UI event 5. Args tail-pass to 0x5c4bd0. type-byte meaning uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4af0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
