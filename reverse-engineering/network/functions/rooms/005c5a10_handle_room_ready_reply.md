# 0x005c5a10 handle_room_ready_reply

| field | value |
|---|---|
| Original address | 0x005c5a10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5a10 |
| Resolved name | handle_room_ready_reply |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005c6fb0
**Referenced globals:** 0x700420/424/428 room-slots; 0x6cbc80 code; 0x6cbc7c conn-hash; 0x6cbc84 err
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cbc84 err-flag

## Behavioral explanation
Processes a room-state reply: on type 0x00 fills room slots 0x700420/424/428 from payload (or zeroes them), on 0x27 sets error, computes conn hash and posts state event 0.

## Notes / uncertainty
Room-ready reply handler: status 0x00 ok publishes room flags/max/handle (+0x1c/+0x20/+0x24) to 0x700420/424/428 (gated on param_2+4), 0x27=error sets 0x6cbc84=0xff; latches code/mode2/hash+event. Uncertainty: param_2+4 identity, FUN_005c6fb0 hash vs handle.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
