# 0x005eed40 finalize_run_metrics

| field | value |
|---|---|
| Original address | 0x005eed40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eed40 |
| Resolved name | finalize_run_metrics |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ef040, FUN_005ef0e0
**Callees:** FUN_005ed1a0, FUN_005ed430
**Referenced globals:** iRam007012a0; +0x182 (max width); +0xd8c0 (run x); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Finalizes a run: on measure pass updates max width +0x182; on draw-position pass stores the run's end x and default height; then resets the cursor and advances the line index.

## Notes / uncertainty
End-of-line finalizer: min-width pass raises +0x182, measure pass writes run-end x + default height +0x180, then commits (ed430) + advances line (ed1a0). ed430/ed1a0 split inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eed40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
