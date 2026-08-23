# 0x00623360 net_role_apply_flags

| field | value |
|---|---|
| Original address | 0x00623360 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623360 |
| Resolved name | net_role_apply_flags |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** —
**Referenced globals:** 0x715298 screen struct ptr; 0x3c98a0 role flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam003c98a0

## Behavioral explanation
Derives the network role from cRam003c98a0 (==2 vs else), writes corresponding struct flags (+0x12,+0xc,+0x10), and returns the role byte.

## Notes / uncertainty
Renamed from net_role_get: reads role 0x3c98a0 AND writes role-dependent screen flags (role2 -> +0x12=1,+0xc=0; else +0xc=1), always +0x10=1, returns role byte. role 2-vs-1 = host/join inferred, not wire-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
