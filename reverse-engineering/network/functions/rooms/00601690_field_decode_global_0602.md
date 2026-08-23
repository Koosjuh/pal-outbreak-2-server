# 0x00601690 field_decode_global_0602

| field | value |
|---|---|
| Original address | 0x00601690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601690 |
| Resolved name | field_decode_global_0602 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c2370
**Referenced globals:** 0x6c0602 global room field (rendered as room name/id in FUN_00601d50/00602340)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate

## Behavioral explanation
Field-sync decoder callback: decodes a single global field into 0x6c0602 via FUN_005c2370, or zeroes it.

## Notes / uncertainty
Field-sync decoder for single global 0x6c0602 (consumed by room-detail/roster renderers FUN_00601d50/00602340). Scalar meaning (room id/host/scenario) unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
