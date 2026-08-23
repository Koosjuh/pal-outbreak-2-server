# 0x005baed0 record_get_dword_0x18

| field | value |
|---|---|
| Original address | 0x005baed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baed0 |
| Resolved name | record_get_dword_0x18 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe1e0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field accessor: returns dword at record+0x18 in table base(0), stride 0x1e4.

## Notes / uncertainty
Sibling of bae80; reads +0x18 dword of current snapshot. Paired scalar consumed with +0x14 by FUN_005fe1e0. Field meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
