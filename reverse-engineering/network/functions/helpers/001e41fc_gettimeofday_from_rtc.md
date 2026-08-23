# 0x001e41fc gettimeofday_from_rtc

| field | value |
|---|---|
| Original address | 0x001e41fc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e41fc |
| Resolved name | gettimeofday_from_rtc |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d53cc, FUN_001e20a0, FUN_001e4728
**Callees:** FUN_00101d08, FUN_00103de8, FUN_0010ea10, FUN_0010f0a8, FUN_001e41d0
**Referenced globals:** 0x24daa0 epoch-sec accum; 0x24daa8 usec accum; 0x25b7c0/c4 tick base; 0x259678.. month/leap table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x24daa0 cached epoch

## Behavioral explanation
Computes current Unix time: reads the RTC (FUN_00101d08, BCD fields), converts date to epoch seconds with a leap-day table, then advances it by elapsed hw ticks (e41d0) into sec/usec written to param_1.

## Notes / uncertainty
gettimeofday: one-time RTC/BCD->epoch seed (leap-aware, month table @0x259678) then tick-advance /300 usec with 1e6 carry. Month-table stride, 300 factor, leap edges interpreted.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e41fc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
