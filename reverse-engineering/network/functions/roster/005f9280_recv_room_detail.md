# 0x005f9280 recv_room_detail

| field | value |
|---|---|
| Original address | 0x005f9280 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9280 |
| Resolved name | recv_room_detail |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005b8cf0, FUN_005c0260, FUN_005c0960, FUN_005c0f20, FUN_005fc850, FUN_005fe1e0, FUN_00618b60
**Referenced globals:** 0x6970a0 (room-detail buffer); 0x6970f4 (member count); 0x6970f6.. (per-member records, stride 0x14a8); 0x6c0778; param+0x908
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x10 (step); 0x6970f4

## Behavioral explanation
On enter-reply, downloads the room detail payload (FUN_005c0f20) into the 0x6970a0 buffer and unpacks it: header flags (cRam006970a0/a1, member count bRam006970f4) plus per-member records (stride 0x14a8: name, slot flags at +0x138, character/color grids), then sends the next step FUN_005c0960(cb 0x5fc360).

## Notes / uncertainty
4-step SM downloading+unpacking room detail into 0x6970a0 (0x29555): header flags, member count 0x6970f4, per-member 0x14a8-stride records (name, sub-record strings, two 0x20x0x20 grids). Grid semantics (char/palette) and 0x76 msg-id->wire-op mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9280.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
