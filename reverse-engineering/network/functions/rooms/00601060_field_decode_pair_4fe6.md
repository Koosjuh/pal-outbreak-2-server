# 0x00601060 field_decode_pair_4fe6

| field | value |
|---|---|
| Original address | 0x00601060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601060 |
| Resolved name | field_decode_pair_4fe6 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00, FUN_005c2890
**Referenced globals:** 0x6c4fe6/0x6c4fe8 paged field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field-sync decoder callback (no mode gate): decodes a value into 0x6c4fe6/0x6c4fe8 via FUN_005c0f00/FUN_005c2890, or zeroes them.

## Notes / uncertainty
Decodes a paired value into 0x6c4fe6/0x6c4fe8 via FUN_005c2890. NOT mode-6 gated (deliberate, unlike siblings) -> persistent field. Pair meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
