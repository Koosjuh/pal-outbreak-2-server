# 0x005bcc30 rtt_probe_start

| field | value |
|---|---|
| Original address | 0x005bcc30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bcc30 |
| Resolved name | rtt_probe_start |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bcee0
**Callees:** —
**Referenced globals:** 0x6ff2ac (probe-running flag); 0x6ff2a8 (accumulated rtt); 0x6ff2ad/0x6ff2ae (recv/timeout counts); 0x6febac (connection handle); REG_RCNT1_* (EE counter1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2ac

## Behavioral explanation
Starts an RTT/latency probe: if not already running, arms hardware counter RCNT1, zeroes sample state (0x6ff2a8/2ac/2ad/2ae) and sends the first 0x40-byte probe (seq byte = sent+recv) via func_0x001dfda0 with reply callback FUN_005bce80.

## Notes / uncertainty
One-shot RTT probe kickoff: arms EE RCNT1, zeroes 0x6ff2a8/ac/ad/ae, sends 64B probe (idx byte) via func_0x001dfda0 cb 0x5bce80. Send-fn arg1 (channel) assumed 0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bcc30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
