# 0x001ca410 snap_lookup_resolve_sm

| field | value |
|---|---|
| Original address | 0x001ca410 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca410 |
| Resolved name | snap_lookup_resolve_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c08e0, FUN_001c3450
**Referenced globals:** 0x35bed8/0x35bee0=resolve out-params; 0x35ccb3=session flag
**Referenced strings:** —
**Referenced opcodes:** 0x62, 0x63, 0x64
**State vars:** puVar3[0]=topstate; puVar3+0xd=phase; puVar3[0x36]=result; puVar3[0x38]=count

## Behavioral explanation
Sub-SM issuing a lookup/keepalive query: phase 0 sends marker 0x62, phase 1 sends 0x63 and resolves via FUN_001c08e0, phase 2 sends 0x64 and on count>=100 sets result state 3.

## Notes / uncertainty
3-phase resolver layered on 0x35ccb3 once-flag: phase0 arms 0x62 and steps +1/+2 by mode; phase1 async resolve FUN_001c08e0 (-1 fail/1 done/0 pending); phase2 settles at count>=100 -> result_state 3. Uncertainty: resolver semantics, why count budget of 100.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca410.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
