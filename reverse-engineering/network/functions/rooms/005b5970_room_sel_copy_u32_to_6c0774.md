# 0x005b5970 room_sel_copy_u32_to_6c0774

| field | value |
|---|---|
| Original address | 0x005b5970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5970 |
| Resolved name | room_sel_copy_u32_to_6c0774 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0860, FUN_005c0f00
**Referenced globals:** 0x6c0774 (0x15c-stride entry table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index, commit a field into entry record at base 0x6c0774 (0x15c stride) via FUN_005c0860.

## Notes / uncertainty
u32 copy src 0x6cfa18 (lowest offset of the config cluster, candidate handle/id) -> dest 0x6c0774. 32-bit field role unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
