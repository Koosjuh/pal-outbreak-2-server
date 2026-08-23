# 0x00607340 roomquery_state2_seed_timer

| field | value |
|---|---|
| Original address | 0x00607340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607340 |
| Resolved name | roomquery_state2_seed_timer |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** —
**Referenced globals:** 0x0070cd78 timer; 0x006c50f4 timer-seed
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070cd78

## Behavioral explanation
State-2: advance step, clear sub-step, seed countdown 0070cd78 from 6c50f4.

## Notes / uncertainty
Trivial: step++, substep=0, reload timer 0x70cd78 from seed 0x6c50f4. Timer units unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
