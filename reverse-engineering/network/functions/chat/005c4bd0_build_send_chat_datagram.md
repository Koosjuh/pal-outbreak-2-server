# 0x005c4bd0 build_send_chat_datagram

| field | value |
|---|---|
| Original address | 0x005c4bd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4bd0 |
| Resolved name | build_send_chat_datagram |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c4af0
**Callees:** FUN_005bf1e0
**Referenced globals:** 0x6febb8 local-username; 0x6febac net-ctx; 0x6ff2b1 in-room-flag; 0x70047c alt-room-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b1 in-room; cRam0070047c room-active

## Behavioral explanation
Builds a DATA datagram [type, senderNameLen, name, payload] and sends via net ctx; picks reliable(0x1000) vs unreliable(0) based on in-room flag.

## Notes / uncertainty
Builds [type,0,nameLen,payLen,0,0,name,payload] and sends reliable op0f (0x1de840). who=0x1000 (lobby DATA broadcast) else 0 (room-scoped) gated on (0x5bf1e0(1)==1 && 0x6ff2b1)||0x70047c. Directly ties chat scope to the 0x6ff2b1 slot-owned gate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
