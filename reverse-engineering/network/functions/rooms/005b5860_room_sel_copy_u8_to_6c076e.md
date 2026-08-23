# 0x005b5860 room_sel_copy_u8_to_6c076e

| field | value |
|---|---|
| Original address | 0x005b5860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5860 |
| Resolved name | room_sel_copy_u8_to_6c076e |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0210, FUN_005c0f00
**Referenced globals:** 0x6c076e (0x15c-stride entry table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index, commit a field into entry record at base 0x6c076e (0x15c stride) via FUN_005c0210.

## Notes / uncertainty
u8 copy src 0x6cfa30 -> dest 0x6c076e; first of the adjacent byte pair (with 5930). Field semantics unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
