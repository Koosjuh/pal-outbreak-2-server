# 0x005bd7e0 get_roster_entry_charstats_6cc128

| field | value |
|---|---|
| Original address | 0x005bd7e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd7e0 |
| Resolved name | get_roster_entry_charstats_6cc128 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070
**Callees:** —
**Referenced globals:** 0x6cc128 (roster 0xf0 blob, stride 0x114)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies roster entry [param&0xff]'s 0xf0-byte blob at 0x6cc128 (stride 0x114) into the caller's buffer.

## Notes / uncertainty
Fixed 0xf0-byte memcpy of charstats blob (+0x24) from 0x6cc104 roster-entry table. Matches member_record charstats.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd7e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
