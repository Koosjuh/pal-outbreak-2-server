# 0x001e4728 rtc_clock_selftest

| field | value |
|---|---|
| Original address | 0x001e4728 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e4728 |
| Resolved name | rtc_clock_selftest |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00101d08, FUN_00114ac8, FUN_001e20a0, FUN_001e41fc
**Referenced globals:** 0x2596a8/0x2596c0/0x2596f0/0x259708/0x259718 fmt strings
**Referenced strings:** clock/date printf format strings at 0x2596a8..0x259718
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Diagnostic that reads the RTC, prints date/epoch (FUN_00114ac8 format strings), sleeps ~5s (e20a0) and re-reads to verify the clock advances.

## Notes / uncertainty
Diagnostic: print date+epoch, sleep (0.5s=0x1dcd6500 ns), reprint to show clock advance. No callers (dead/debug). Format-string text not dumped; first sleep interval DAT_0025b7c8 unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e4728.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
