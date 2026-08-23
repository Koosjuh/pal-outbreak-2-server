# 0x005e9490 emit_segment_and_reset

| field | value |
|---|---|
| Original address | 0x005e9490 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9490 |
| Resolved name | emit_segment_and_reset |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70, FUN_005ef1a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Applies argument via FUN_005eef70 then triggers refresh FUN_005ef1a0.

## Notes / uncertainty
FUN_005eef70 emits segment into ctx+0x1540[ctx+0x188] then FUN_005ef1a0 resets 0x40c block defaults (+0x4e8=0x100,+0x6ec/+0x6ee=0x1e). Upgraded Medium->High. 'segment' granularity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9490.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
