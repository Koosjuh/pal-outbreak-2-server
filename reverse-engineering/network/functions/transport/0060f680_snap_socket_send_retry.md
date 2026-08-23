# 0x0060f680 snap_socket_send_retry

| field | value |
|---|---|
| Original address | 0x0060f680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f680 |
| Resolved name | snap_socket_send_retry |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e060
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Transport send wrapper: chooses func_0x0011a9f8 (3-arg) vs func_0x0011aa18 (4-arg, when param_4!=0) and retries up to param_5 times (or infinitely if 0) until >=0.

## Notes / uncertainty
send/sendto retry wrapper: 2x2 branch on addr(param_4) and bounded(param_5). Syscalls 0x11a9f8/0x11aa18 opaque; return value dropped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
