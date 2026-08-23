# 0x00600ff0 field_decode_global_5510

| field | value |
|---|---|
| Original address | 0x00600ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600ff0 |
| Resolved name | field_decode_global_5510 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0fd0
**Referenced globals:** 0x6c5510 global field (later rendered as room timer, see FUN_00601c00)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate; uRam006c4600 player index

## Behavioral explanation
Field-sync decoder callback: decodes a single global field into 0x6c5510 via FUN_005c0fd0, or zeroes it.

## Notes / uncertainty
Field-sync decoder for single global 0x6c5510 (consumed by timer renderer FUN_00601c00 -> likely room timer/countdown). Units unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
