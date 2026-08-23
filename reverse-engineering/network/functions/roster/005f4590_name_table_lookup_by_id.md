# 0x005f4590 name_table_lookup_by_id

| field | value |
|---|---|
| Original address | 0x005f4590 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4590 |
| Resolved name | name_table_lookup_by_id |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** iRam00343628(name/entry table base); cRam0034359d(region: picks name offset +8 vs +0x28); 0x702040(output name buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0034359d

## Behavioral explanation
Scans a local 0x7f-entry table (stride 0x58) for a matching id byte and copies the associated name string to 0x702040.

## Notes / uncertainty
Id-byte lookup in preloaded table (0x343628, stride 0x58, id@+1), copies localized name (col +8 or +0x28 by region flag 0x34359d) to 0x702040. No caller xref; table domain inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
