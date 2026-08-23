# 0x005bce80 rtt_probe_reply_handler

| field | value |
|---|---|
| Original address | 0x005bce80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bce80 |
| Resolved name | rtt_probe_reply_handler |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bcce0
**Referenced globals:** 0x6ff2ad/0x6ff2ae (sample counts); REG_RCNT1_COUNT
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
RTT probe reply handler: if the reply's sequence byte matches the expected sample index (sent+recv), reads RCNT1 and feeds the measured latency ((count*30)/0x3840) into rtt_probe_accumulate.

## Notes / uncertainty
Probe reply cb: gate on payload[0]==expected index (ok+timeout), else drop; feeds (RCNT1*0x1e)/0x3840 latency into accumulate. param_1 ctx layout undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bce80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
