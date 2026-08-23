# 0x005b57e0 room_sel_copy_u16_to_6c3032

| field | value |
|---|---|
| Original address | 0x005b57e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b57e0 |
| Resolved name | room_sel_copy_u16_to_6c3032 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bfcb0, FUN_005c0f00
**Referenced globals:** 0x6c3032 (0x15c-stride entry table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index, commit a field into entry record at base 0x6c3032 (0x15c stride) via FUN_005bfcb0.

## Notes / uncertainty
Config field-marshal: copies u16 of record[sel] (src table @0x6cf142, stride 0x144) into UI entry sel-1 (@0x6c3032, stride 0x15c). Mechanism clear; field meaning unknown; the 0x6cf142 sub-table is distinct from the 0x6cfa1x cluster. No runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b57e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
