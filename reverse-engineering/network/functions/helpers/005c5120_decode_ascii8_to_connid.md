# 0x005c5120 decode_ascii8_to_connid

| field | value |
|---|---|
| Original address | 0x005c5120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5120 |
| Resolved name | decode_ascii8_to_connid |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb670, FUN_005bbfc0, FUN_005bc050, FUN_005bc430, FUN_005c4d20, FUN_005c6500
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Decodes the 8-char ASCII connID token back into a 32-bit connID/target value.

## Notes / uncertainty
Inverse of encoder; char[0]<<28 (no -0x30) is a benign optimization since '0'&0xf==0. No input validation. Runtime cross-check pending.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
