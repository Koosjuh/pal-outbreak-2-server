# 0x00601170 field_decode_room_counts_0764

| field | value |
|---|---|
| Original address | 0x00601170 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601170 |
| Resolved name | field_decode_room_counts_0764 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005adc80, FUN_005c0370
**Referenced globals:** 0x6c0764/66/68/6a/6c per-player room fields (0x15c stride)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate

## Behavioral explanation
Field-sync decoder callback: decodes five per-player 2-byte fields at 0x6c0764/66/68/6a/6c via FUN_005c0370 (or zeroes them) — includes 0x6c076a, the room capacity/count used for join gating.

## Notes / uncertainty
Registered field decoder (via FUN_005c02b0). For current room slot ((ord-1)*0x15c) OK->FUN_005c0370 decodes 5 u16s at 0x6c0764/66/68/6a/6c; err->zeroes them. 0x6c076a=cur-player count on join-gate path (create-room 1/0p bug). Per-field meanings beyond 0x6c076a unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
