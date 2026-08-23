# 0x005c2a40 scenario_record_ptr

| field | value |
|---|---|
| Original address | 0x005c2a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2a40 |
| Resolved name | scenario_record_ptr |
| Subsystem | lobby |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c2a70, FUN_005c2a90, FUN_005c2ab0, FUN_005c2ae0, FUN_005c2b20, FUN_005c2b50, FUN_005c2b70, FUN_005c2b90
**Callees:** —
**Referenced globals:** iRam00368474 (scenario/area record table base, stride 0x1e4)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Base+index accessor: returns &scenario/area-record[param_1] in the 0x1e4-stride table based at iRam00368474.

## Notes / uncertainty
Root accessor: iRam00368474 + (idx&0xffff)*0x1e4. Base of the whole 0x2axx family. Full 0x1e4 record layout only partially known.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
