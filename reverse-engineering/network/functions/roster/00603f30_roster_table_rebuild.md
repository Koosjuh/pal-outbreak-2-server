# 0x00603f30 roster_table_rebuild

| field | value |
|---|---|
| Original address | 0x00603f30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603f30 |
| Resolved name | roster_table_rebuild |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00603e40
**Callees:** FUN_00604770, FUN_00604860, FUN_006048f0, FUN_00604af0, FUN_00618b60
**Referenced globals:** 0x70b470 (per-member flag array); 0x70b4b0 (roster table base); 0x70b4c0 (member id key); 0x70b4d0 (member status); 0x694700 (persistent member pool); ctx+0x905 (built count); ctx+0x914 (free-slot count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x905; ctx+0x914

## Behavioral explanation
Rebuilds the active member roster table at 0x70b4b0 (0x38-stride) by scanning up to 0x32 source records at overlay+0xc8000, resolving each id against pools 0x694700 to set per-member status (0/2/3) at +0x70b4d0, counts members into ctx+0x914, then builds the roster UI draw jobs via FUN_00604af0.

## Notes / uncertainty
Rebuilds active roster 0x70b4b0 (stride 0x38) from 0x32 source records (overlay+0xc8000), status 0/2/3 via pool 0x694700 lookup, occupied count into ctx+0x914. Decompiler source-addr recurrence has an extra +i term (treated as strength-reduction artifact, effective stride 0x10) — flagged for runtime check.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603f30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
