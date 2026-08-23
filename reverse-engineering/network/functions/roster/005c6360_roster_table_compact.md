# 0x005c6360 roster_table_compact

| field | value |
|---|---|
| Original address | 0x005c6360 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6360 |
| Resolved name | roster_table_compact |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500
**Callees:** —
**Referenced globals:** 0x6ff2b5 accept-flags; 0x6ff70d member-src-tbl; 0x700710/0x700b60 compact-out; 0x700708 accepted-count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00700708 accepted-count

## Behavioral explanation
Compacts accepted members (flag 0x6ff2b5==1) from source table 0x6ff70d into contiguous output tables 0x700710/0x700b60 and counts them in 0x700708.

## Notes / uncertainty
Compacts accepted members (accept flag 0x6ff2b5==1) from 0x6ff70d (stride 0x114 member_record) into contiguous 0x700710/0x700b60, counts in 0x700708. Slot-0 name-mirror exclusion inferred as self/creator.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6360.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
