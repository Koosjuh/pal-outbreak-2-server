# 0x001c08e0 resolve_hostname_cached

| field | value |
|---|---|
| Original address | 0x001c08e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c08e0 |
| Resolved name | resolve_hostname_cached |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9850, FUN_001ca410
**Callees:** FUN_0010a338, FUN_0010a4f0, FUN_001c0690, FUN_001ee7c0, FUN_001ee810, FUN_001ee860
**Referenced globals:** 0x35c3f0 dns-cache; 0x35c4f0 ip-slots; 0x35c3e0 idx; 0x35cc10 pending-handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *param_1 resolve-state; 0x35c3e0

## Behavioral explanation
gethostbyname-style resolver: parses literal IP or searches/loads an 8-slot cache, launching async DNS (FUN_001ee7c0/860/810) with a *param_1 state (0 idle / 1 pending).

## Notes / uncertainty
Non-blocking cached gethostbyname: literal-parse -> 8-slot cache (0x35c3f0, stride 0x104) -> async DNS (FUN_001ee7c0/860/810), state 0 idle/1 pending, ret 1/0/-1. DNS codes 1=ready,-3=busy,else err. param_4 hostname type inferred; State-0 literal convention inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c08e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
