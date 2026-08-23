# 0x005ec170 measure_accumulate_width

| field | value |
|---|---|
| Original address | 0x005ec170 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec170 |
| Resolved name | measure_accumulate_width |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eacd0, FUN_005ed1f0, FUN_005ed460, FUN_005ee840, FUN_005eef70, FUN_005ef040, FUN_005ef0e0, FUN_005f2450, FUN_005f3230, FUN_005f3310, FUN_005f39d0, FUN_005f3ac0, FUN_005f3bc0, FUN_005f3cc0
**Callees:** —
**Referenced globals:** iRam007012a0; +0x184 (max width acc); +0x186 (pass flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
On the measure pass (+0x186==0) accumulates a run's width (param+10 + param+6) into the running max width +0x184.

## Notes / uncertainty
Measure sink: on +0x186==0 raises max content width +0x184 to box->x+width. Note pass polarity differs from attr handlers (0 vs 0xf6) => +0x186 is multi-valued.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
