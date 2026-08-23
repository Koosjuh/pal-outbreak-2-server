# 0x00604770 member_id_absent_from_roster

| field | value |
|---|---|
| Original address | 0x00604770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604770 |
| Resolved name | member_id_absent_from_roster |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00603f30
**Callees:** —
**Referenced globals:** 0x70b4c0 (member id keys); 0x6c69cc (reserved/self id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans the 0x32-entry roster (stride 0x38, key +0x70b4c0) for a duplicate of the given 0x10-byte member id; returns 1 if unique/appendable, 0 on collision or reserved-id match (0x6c69cc).

## Notes / uncertainty
Scans 0x32-entry roster (0x70b4c0/0x38, id+0x10) vs reserved id 0x6c69cc. NOTE: decompiled break-path returns 0 on BOTH inner branches; only table-exhaustion returns 1 - unusual, exact predicate (uniqueness vs reserved-run) flagged uncertain, name [inferred].

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
