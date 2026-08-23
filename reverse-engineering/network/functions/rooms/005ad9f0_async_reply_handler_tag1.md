# 0x005ad9f0 async_reply_handler_tag1

| field | value |
|---|---|
| Original address | 0x005ad9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad9f0 |
| Resolved name | async_reply_handler_tag1 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005f74d0
**Referenced globals:** 0x6c4fbb(pending); 0x6c4b90(screen); 0x6c4b9f/0x6c4ba0/0x6c4ba1/0x6c4ba2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Async reply callback (pending fbb==1): on ok byte0==0 calls success path 5f74d0, else jumps screen state to 6 and shows error box.

## Notes / uncertainty
Async reply cb for pending_tag(0x6c4fbb)==1, guarded screen_id!=6. status[0]==0 -> success FUN_005f74d0; else screen_major(0x6c4b9f)=6 + error dialog on 0x6c517c. Registered by FUN_005ad680 case3/4. Uncertainty: which op the reply is for.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
