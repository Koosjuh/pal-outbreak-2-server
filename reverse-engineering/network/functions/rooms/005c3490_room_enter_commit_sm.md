# 0x005c3490 room_enter_commit_sm

| field | value |
|---|---|
| Original address | 0x005c3490 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3490 |
| Resolved name | room_enter_commit_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf1e0, FUN_005c2ae0, FUN_005c2b70, FUN_005c4f00
**Referenced globals:** 0x6cba78/7c/7d (SM state/enable/reply); 0x6ff2b1 (scenario/title ownership LOCK, set=1); 0x6cc01a/0x6cc03b (name/pw buffers); 0x6ca888 (selected scenario id); 0x6febe4 (outgoing conn flags); 0x7004d0..0x7005c0 (request packet); 0x6d2295/96 (config flags/count)
**Referenced strings:** —
**Referenced opcodes:** 0x06, 0x0c
**State vars:** cRam006cba78; cRam006cba7c; cRam006cba7d; uRam006ff2b1

## Behavioral explanation
Large enter/create-commit state machine (0x6cba78/7c/7d): builds the room-enter request packet (scenario id, player/difficulty bitfields, flags into 0x6febe4) at 0x7004d0/0x7005b0/0x7005c0 and sends via 0x1de470; on ACK sets the ownership lock uRam006ff2b1=1, uRam006cbc7e=0x10 and kicks bdfe0(0x18).

## Notes / uncertainty
Create-commit SM: step0 builds request 0x7004d0 (scenario id/difficulty/flags 0x6febe4) and sends op0c PREPARE; step1 sends op04 create-room; step2 on ACK sets create-boundary lock 0x6ff2b1=1, UI 0x6cbc7e=0x10, redraw 0x18. Send sequence+commit certain; step0 scenario/difficulty bitfield packing ambiguous (decompiler register aliasing).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3490.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
