# 0x001ce810 member_id_present_in_any_group_roster

| field | value |
|---|---|
| Original address | 0x001ce810 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce810 |
| Resolved name | member_id_present_in_any_group_roster |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x36c310 group table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans all 4 group rosters (short array at ptr+4, up to 0x640 entries) for a member id==param_1; returns 1 if present.

## Notes / uncertainty
Scans each active group's roster body (u16[] @roster_buf+4, 0x640=1600 entries) for id; returns 1 if present. 1600*2=0xc80 corroborates buffer body size from FUN_001ce4b0. No captured callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
