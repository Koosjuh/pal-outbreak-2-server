# 0x00617110 room_phase02_broadcast_selects

| field | value |
|---|---|
| Original address | 0x00617110 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617110 |
| Resolved name | room_phase02_broadcast_selects |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40
**Callees:** FUN_005af2f0, FUN_00617bb0
**Referenced globals:** 0x70f330 (4-byte select scratch)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x990 player-count; +0xc/+9/+8 room-id fields

## Behavioral explanation
Room phase-2: builds a 4-byte per-player selection array (from each player's +0x22c8/+0x22ca) at 0x70f330 and submits it to the network layer (func_0x001d40e0), then latches room id fields from +0x1f18.

## Notes / uncertainty
Already fully reconstructed and accurate vs raw (two-step 0xf latch preserved). Unresolved: exact opcode/who-byte emitted by transport primitive func_0x001d40e0(0,0,buf); sentinel 8 meaning inferred. Not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
