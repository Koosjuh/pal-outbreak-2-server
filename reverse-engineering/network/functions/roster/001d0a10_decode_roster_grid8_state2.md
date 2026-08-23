# 0x001d0a10 decode_roster_grid8_state2

| field | value |
|---|---|
| Original address | 0x001d0a10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0a10 |
| Resolved name | decode_roster_grid8_state2 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d2970
**Callees:** FUN_001d09e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Calls FUN_001d09e0 then stamps byte@(param_2+2)=2 to tag the decoded grid as state-2.

## Notes / uncertainty
State-2 variant: runs FUN_001d09e0 (which clears dst[2]=0) then stamps dst[2]=2. Decompiler dropped forwarded args (assumed pass-through). Renderer difference of state 0 vs 2 not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
