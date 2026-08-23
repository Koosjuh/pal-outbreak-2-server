# 0x006000e0 chat_message_recv_append

| field | value |
|---|---|
| Original address | 0x006000e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006000e0 |
| Resolved name | chat_message_recv_append |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5fb0
**Callees:** —
**Referenced globals:** iRam003435d4+0xc942c member-slot table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** slot+0x28/0x2c buffer length; slot+1 type

## Behavioral explanation
Inbound message handler: matches sender against the 4 member slots (0x14-byte id), sets slot type (4/1 = self-echo vs 2 = remote), and appends the payload (+0x18 len) into that slot's growing buffer at +0x2c/+0x28.

## Notes / uncertainty
Inbound counterpart: matches sender by slot+0x14 id, sets type (4=final/complete+flag3, 2=continuation) and appends payload into slot+0x30 advancing cursors +0x28/+0x2c. Record layout {id[0x14],flag,len,data}. Copy-length source (thunk-internal vs len) inferred; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006000e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
