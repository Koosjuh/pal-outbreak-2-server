# 0x006101d0 roomlist_fetch_sm

| field | value |
|---|---|
| Original address | 0x006101d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006101d0 |
| Resolved name | roomlist_fetch_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910, FUN_00610580
**Callees:** FUN_0060e710, FUN_0060eaa0, FUN_0060eba0, FUN_0060ec60, FUN_0060ed40, FUN_0060ef20, FUN_0060f0c0, FUN_00618210, FUN_00618230, FUN_00618510, FUN_00618520, FUN_00618530
**Referenced globals:** iRam0070d1c0 (context); ctx+0x2c (fetch sub-state); ctx+0x25 (page-avail bitmask); ctx+0x1180 (net ctx); ctx+0x10d8 (recv/dialog obj)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x2c fetch state; ctx+0x25/0x26/0x2f page cursor

## Behavioral explanation
State machine (switch ctx+0x2c) that opens/pages the room list: recv via FUN_00618230/18520/18530, records available pages in bitmask +0x25, then FUN_0060ef20 opens the query, counts modes, and on success builds+registers rooms (FUN_0060ed40) and indexes them (FUN_0060e710). Returns -3/-2/-1/0/1.

## Notes / uncertainty
Already fully reconstructed: 6-state pager over recv-object 0x10d8, 2-bit page mask 0x25, builds+indexes records via 0060ed40/0060e710 (sole caller of roomtable_find_by_keys). Meaning of the three mode-count buckets (sel 0/2/1) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006101d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
