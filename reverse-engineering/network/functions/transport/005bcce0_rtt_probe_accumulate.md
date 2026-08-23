# 0x005bcce0 rtt_probe_accumulate

| field | value |
|---|---|
| Original address | 0x005bcce0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bcce0 |
| Resolved name | rtt_probe_accumulate |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bce20, FUN_005bce80
**Callees:** —
**Referenced globals:** 0x6ff2a8 (rtt sum); 0x6ff2ad/0x6ff2ae (success/timeout counts); 0x86f858/0x86f850/0x86f848 (published rtt stats); 0x6febac (conn handle); REG_RCNT1_*
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006ff2ad; bRam006ff2ae

## Behavioral explanation
Accumulates one RTT sample: negative arg counts a timeout (0x6ff2ae), non-negative adds to the RTT sum (0x6ff2a8) and bumps the success count; keeps sending 0x40-byte probes until 8 samples collected, then stops the timer and publishes sum/success/timeout to 0x86f858/0x86f850/0x86f848.

## Notes / uncertainty
Core of 8-sample RTT loop: <0 timeout else add latency; continues probing until 8 then stops RCNT1 (mode 0x83) and publishes sum/ok/timeout to 0x86f858/850/848. Units of published sum unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bcce0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
