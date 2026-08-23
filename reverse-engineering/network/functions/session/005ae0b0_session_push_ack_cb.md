# 0x005ae0b0 session_push_ack_cb

| field | value |
|---|---|
| Original address | 0x005ae0b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae0b0 |
| Resolved name | session_push_ack_cb |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4b90(screen); 0x6c4b9e(nav); 0x6c517c(err ctx)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4b9e

## Behavioral explanation
Callback for the screen7 session-table push: on ok byte0==0 sets nav 0x6c4b9e=8, else increments it and shows error box (5be9a0).

## Notes / uncertainty
Session-table push completion cb (registered by addr in FUN_005ade20 case 3). reply byte0==0 -> lobby_sm(0x6c4b9e)=8; else lobby_sm++ + error dialog FUN_005be9a0(0x6c517c); gated off when screen_id(0x6c4b90)==6. Which SN@P reply feeds it not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae0b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
