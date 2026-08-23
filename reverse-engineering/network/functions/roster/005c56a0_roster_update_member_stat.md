# 0x005c56a0 roster_update_member_stat

| field | value |
|---|---|
| Original address | 0x005c56a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c56a0 |
| Resolved name | roster_update_member_stat |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdf90
**Referenced globals:** 0x6fee8c roster-connid-key; 0x6fee84 stat-field; 0x6cfb5c member-flags; 0x6d2158 sel; 0x6cbc7e mode
**Referenced strings:** STAT
**Referenced opcodes:** —
**State vars:** sRam006d2158 sel

## Behavioral explanation
On a 'STAT' (0x53544154) message for a known member: updates that member's status field/flags and fires UI event 0x29.

## Notes / uncertainty
'STAT'(0x53544154)-gated per-member status update: writes id-slot+0x18 and display flags(>>1), sets roster panel mode 0x6cbc7e=0x10, fires UI event 0x29. Reads as the in-room ready/char-status sub-message.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c56a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
