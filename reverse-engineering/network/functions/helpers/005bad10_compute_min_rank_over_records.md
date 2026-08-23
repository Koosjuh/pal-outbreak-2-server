# 0x005bad10 compute_min_rank_over_records

| field | value |
|---|---|
| Original address | 0x005bad10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bad10 |
| Resolved name | compute_min_rank_over_records |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00616d30, FUN_006173c0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loops param_3 rows of a 0x3b0-stride record, copying 0xd4 bytes to a stack buffer and comparing element auStack_a4[idx] against three thresholds at (param_2 + 0x12e8) to derive a min rank (0..3).

## Notes / uncertainty
Grades u16 stat column (col=param_4&0xf) across `count` records (stride 0x3b0, stat block +0x2a4) vs 3 ascending thresholds at +0x12e8; returns MIN rank 0..3. Control flow certain; domain meaning + threshold signedness open. Non-net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bad10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
