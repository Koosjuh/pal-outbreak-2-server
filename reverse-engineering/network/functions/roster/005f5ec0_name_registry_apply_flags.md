# 0x005f5ec0 name_registry_apply_flags

| field | value |
|---|---|
| Original address | 0x005f5ec0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5ec0 |
| Resolved name | name_registry_apply_flags |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005fe620
**Callees:** —
**Referenced globals:** 0x70a164(per-name status table, stride 0x30); 0x695d60(name registry)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70a17c bit7 (dirty), 0x695d60+0x2c (status)

## Behavioral explanation
Walks a 100-entry status table (0x70a164) and, for flagged entries, copies the low-7 status bits into the matching name-registry slot.

## Notes / uncertainty
Syncs dirty (bit7) status entries from 0x70a164 into registry +0x2c (low-7 bits) by name match. (n2+n)*0x10 index resolves to 0x30 stride. Status-bit meanings not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5ec0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
