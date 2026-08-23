# 0x00600e90 field_decode_player_status

| field | value |
|---|---|
| Original address | 0x00600e90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600e90 |
| Resolved name | field_decode_player_status |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0860
**Referenced globals:** 0x6c0618/0x6c0774 per-player record (0x15c stride); 0x6c4b96 mirror
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate; bRam006c4600 current player index

## Behavioral explanation
Field-sync decoder callback: decodes the current player's status field (FUN_005c0860 into (idx)*0x15c+0x6c0774) and mirrors a byte into 0x6c4b96, else zeroes it.

## Notes / uncertainty
Field-sync decoder (mode!=6 gate, tag0=decode/nonzero=reset); decodes player status into room-slot flags 0x6c0774, mirrors byte to 0x6c4b96. idx vs idx-1 decode/reset quirk unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
