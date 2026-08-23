# 0x00615430 restore_room_config_form

| field | value |
|---|---|
| Original address | 0x00615430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615430 |
| Resolved name | restore_room_config_form |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060f910, FUN_00610830
**Callees:** —
**Referenced globals:** 0x3c9594 (src); iRam0070d1c0+0xed0 (dest)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0xed0

## Behavioral explanation
Copies the 65x8B table from 0x3c9594 into iRam+0xed0 (restore/load).

## Notes / uncertainty
RENAMED from roster_table_restore: 520-byte (65x8) copy from 0x3c9594 into room-create form area ctx+0xed0 (fields used by pack_room_config_globals), inverse of FUN_00615470 - not a roster. Snapshot-vs-template nature unresolved; confidence Medium (mechanics exact, meaning inferred).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00615430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
