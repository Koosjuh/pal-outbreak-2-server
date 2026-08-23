# 0x001ce970 reconcile_state1_roster

| field | value |
|---|---|
| Original address | 0x001ce970 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ce970 |
| Resolved name | reconcile_state1_roster |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001841d0, FUN_001cbc20, FUN_001cd620, FUN_001cda90, FUN_001cde00, FUN_001ce4b0, FUN_001ce740, FUN_001ce890, FUN_001cf360
**Referenced globals:** 0x4f9f80 area index array; 0x3c18b0 area base table; 0x4f8be0 member index arrays; 0x4f8d60 member arrays; 0x4fa6f0 member flag array; cRam004fa638 suppress-reconcile flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam004fa638

## Behavioral explanation
Diffs the state-1 entity snapshot (via FUN_001ce890) against live member arrays (0x4f9f80/0x4f8be0/0x4f8d60); applies leaves (FUN_001cda90/FUN_001cd620/FUN_001ce4b0) and joins (FUN_001cde00/FUN_001ce740), then flushes via FUN_001841d0.

## Notes / uncertainty
Rewrote to full reconstruction. State-1 cache-vs-live reconcile: snapshot (ce890, state==1 entries in caches 0x36c350/420/310) diffed against live arrays 0x4f9f80/0x4f8be0/0x4f8d60; survivors=stale->torn down (cda90/cd620/ce4b0), then full live set re-registered via op09 (cde00, chan 0x1200, attr 0x80000002) + roster refill (ce740). LEAVE polarity CONFIRMED by reading cda90 (arg1==4 => refcount-dec/detach) and cde00 (state from DAT_0024c7f8, register/inc). Gated by suppress flag 0x4fa638. ce890 tex-guard reads model byte3 (quirk) preserved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ce970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
