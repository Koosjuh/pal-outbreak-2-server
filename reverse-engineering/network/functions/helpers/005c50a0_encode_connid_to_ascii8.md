# 0x005c50a0 encode_connid_to_ascii8

| field | value |
|---|---|
| Original address | 0x005c50a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c50a0 |
| Resolved name | encode_connid_to_ascii8 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb4d0, FUN_005bb670, FUN_005bbb90, FUN_005c0ae0, FUN_005c2460
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Encodes a 32-bit connID into 8 ASCII nibble-chars (each nibble + 0x30) — inverse of decode_ascii8_to_connid.

## Notes / uncertainty
Encodes 32-bit connID to 8 ASCII chars, nibble+0x30 MSB-first (NOT hex: 0xA-0xF -> :;<=>?). Inverse of 0x5c5120. Wire cross-check pending.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c50a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
