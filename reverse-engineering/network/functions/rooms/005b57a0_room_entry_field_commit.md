# 0x005b57a0 room_entry_field_commit

| field | value |
|---|---|
| Original address | 0x005b57a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b57a0 |
| Resolved name | room_entry_field_commit |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf940, FUN_005c0f00
**Referenced globals:** 0x6c3862 (0x15c-stride room/config entry table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index (FUN_005c0f00), commit a field into that entry's 0x15c-stride record at base 0x6c3862 via FUN_005bf940.

## Notes / uncertainty
Field-commit glue: reads 1-based selected list index (FUN_005c0f00), writes +2 field of room-cfg record (idx-1)*0x15c+0x6c3862 via FUN_005bf940. Table 0x6c3860 stride 0x15c matches the one ad680 clears (10 records). Uncertainty: what the +2 field is and what value is stored; sibling fns write other offsets.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b57a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
