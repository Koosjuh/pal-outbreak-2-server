# 0x005bf3c0 get_registry_entry_field_0x6ce5f2

| field | value |
|---|---|
| Original address | 0x005bf3c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf3c0 |
| Resolved name | get_registry_entry_field_0x6ce5f2 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890
**Callees:** —
**Referenced globals:** 0x6ce5f2 registry-A render struct (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
memcpy's a per-entry field at (idx-1)*0x144+0x6ce5f2 (registry-A render struct) out to caller buffer.

## Notes / uncertainty
strcpy of string field @+0x158 from 0x144-stride registry table, 1-BASED index ((id-1)*0x144) matching op06 count table/room-id convention. id 0 underflows (unguarded).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf3c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
