# 0x005af370 ui_init_two_tables_from_template

| field | value |
|---|---|
| Original address | 0x005af370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af370 |
| Resolved name | ui_init_two_tables_from_template |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ac610
**Callees:** —
**Referenced globals:** 0x6951f0 table A; 0x694700 table B; 0x3c8a90 template
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes/snapshots two 0xaf0-byte tables (0x6951f0 and 0x694700) by memcpy from a template at 0x3c8a90.

## Notes / uncertainty
Two memcpy(0xAF0) from template 0x3c8a90 into tables 0x6951f0 & 0x694700 (identical src). Renamed from 'snapshot' (misnomer) to template-load/reset. Paired-table purpose (current/shadow) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
