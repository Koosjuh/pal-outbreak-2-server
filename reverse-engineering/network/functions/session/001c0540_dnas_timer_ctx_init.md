# 0x001c0540 dnas_timer_ctx_init

| field | value |
|---|---|
| Original address | 0x001c0540 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0540 |
| Resolved name | dnas_timer_ctx_init |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001eeb50
**Referenced globals:** 0x35a6d8 =0x1863c; 0x35c3d8 mode; 0x35b720 timer-ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35c3d8 mode; 0x35b720

## Behavioral explanation
Initializes an auth-timing struct at 0x35b720 (params, timeout scaled from 0x1863c/100); frees prior handle via FUN_001eeb50 when mode(0x35c3d8) is 2 or 3.

## Notes / uncertainty
Inits DNAS timer/param ctx @0x35b720: 2 caller bytes + timeout base 0x1863c stored /100=1000 at +0x12, zero-clears rest; frees prior handle (FUN_001eeb50) when mode *0x35c3d8 in {2,3}. Mode labels connecting/established inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
