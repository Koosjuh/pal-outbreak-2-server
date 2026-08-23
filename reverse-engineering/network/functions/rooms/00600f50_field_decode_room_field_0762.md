# 0x00600f50 field_decode_room_field_0762

| field | value |
|---|---|
| Original address | 0x00600f50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600f50 |
| Resolved name | field_decode_room_field_0762 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c01d0
**Referenced globals:** 0x6c0606/0x6c0762 per-player field (0x15c stride)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate; bRam006c4600 player index

## Behavioral explanation
Field-sync decoder callback: decodes a per-player 2-byte field (FUN_005c01d0 into (idx)*0x15c+0x6c0762) or zeroes it on reset.

## Notes / uncertainty
Renamed from field_decode_player_field_0602 to match decode addr 0x6c0762 (=pairA drawn for type>=3 rooms). 2-byte per-room field; reset addr 0x6c0606. Value semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600f50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
