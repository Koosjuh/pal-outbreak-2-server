# 0x005bce20 rtt_probe_poll_timeout

| field | value |
|---|---|
| Original address | 0x005bce20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bce20 |
| Resolved name | rtt_probe_poll_timeout |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005be330
**Callees:** FUN_005bcce0
**Referenced globals:** REG_RCNT1_COUNT/MODE (EE counter1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Polls the RCNT1 timer; if the probe has exceeded its window (elapsed>1 unit or overflow bit set) it records a timeout by calling rtt_probe_accumulate(-1).

## Notes / uncertainty
Per-frame watchdog: RCNT1 count/0x3840>1 or overflow bit 0x800 -> accumulate(-1). Real-time span of 0x3840 window unmeasured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bce20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
