# 0x005bae80 record_get_dword_0x14

| field | value |
|---|---|
| Original address | 0x005bae80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bae80 |
| Resolved name | record_get_dword_0x14 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f78c0, FUN_005fe1e0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field accessor: returns dword at record+0x14 in table base(0), stride 0x1e4.

## Notes / uncertainty
Accessor into double-buffered 0x1e4-stride record table via ptr-array 0x6c5480 (FUN_005bac60(0)=current). Reads +0x14 dword (a diff-compared scalar). Record domain (room-list vs lobby-list) inferred from renderer callers, not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bae80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
