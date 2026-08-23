# 0x005bac60 get_record_table_base

| field | value |
|---|---|
| Original address | 0x005bac60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bac60 |
| Resolved name | get_record_table_base |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bae30, FUN_005bae80, FUN_005baed0, FUN_005baf20, FUN_005baf70, FUN_005bafc0, FUN_005bb010, FUN_005bb060, FUN_005bb0b0, FUN_00616d30, FUN_006173c0
**Callees:** —
**Referenced globals:** 0x006c5480 record-table base-pointer array [2]
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor returning *(0x6c5480 + i*4): base pointer of one of two parallel record buffers (roster/player records, stride 0x1e4); index 0 = current, 1 = previous snapshot.

## Notes / uncertainty
Accessor *(0x6c5480+i*4): 2-entry base-ptr array, [0]=current record buffer, [1]=prev snapshot (0x6c5484); 0x1e4-byte records. Shared by all record_get_* getters + the diff.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bac60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
