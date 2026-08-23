# 0x005b5930 room_sel_copy_u8_to_6c076f

| field | value |
|---|---|
| Original address | 0x005b5930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5930 |
| Resolved name | room_sel_copy_u8_to_6c076f |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c09c0, FUN_005c0f00
**Referenced globals:** 0x6c076f (0x15c-stride entry table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index, commit a field into entry record at base 0x6c076f (0x15c stride) via FUN_005c09c0.

## Notes / uncertainty
u8 copy src 0x6cfa31 -> dest 0x6c076f; second of the byte pair. Field semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
